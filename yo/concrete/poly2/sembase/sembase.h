#ifndef INCLUDED_SEMBASE_
#define INCLUDED_SEMBASE_

#include <type_traits>
#include <memory>
#include <vector>
#include <iosfwd>

class SemBase;

//TAG
enum class Tag          // defines the various semantic values
{                       // Tags are used to instantiate the proper
    INT,                // Semantic type, deriving from a polymorphic base
    TEXT,               // class
    VECTOR,
};
//=

    // In separate anonymous namespace sections parts of the various semantic
    // types are defined. Sections labeled 'IUO' are `Internal Use Only' and
    // contain no serviceable parts

namespace {     // IUO
//MUTABLE
    struct Mutable                          // Semantic values may or may
    {                                       // not be mutable. By deriving
        enum: bool { isMutable = true };    // BasicTrait, below, from
    };                                      // either Mutable or Immutable
                                            // this trait is associated with
    struct Immutable                        // a semantic value BasicTrait.
    {
        enum: bool { isMutable = false };
    };
//=

    // For each semantic value type define a TagTrait specialization which
    // is either derived from Immutable (in which case the Parser cannot
    // change the semantic value) or from Mutable (In which case changing the
    // semantic value on the semantic value stack *is* allowed)
    // In addition, define the data type to use, as received in the
    // initialization (e.g., int, std::string, vector<spSemBase>).
//TRAITTAG
    template <Tag tag>
    struct TagTrait;

    template <>
    struct TagTrait<Tag::INT>: public Immutable
    {
        typedef int DataType;
    };

    template <>
    struct TagTrait<Tag::TEXT>: public Immutable
    {
        typedef std::string DataType;
    };

    template <>
    struct TagTrait<Tag::VECTOR>: public Mutable
    {
        typedef std::vector<std::shared_ptr<SemBase const>> DataType;
    };
//=

    // In this section of the anonymous namespace it is determined whether a
    // semantic value type is a basic type (in which case the return type of
    // the Semantic class's conversion operator can be equal to the type
    // itself) or a class-type (in which case a reference is returned).
   /// Its logic is based on two function templates 'test' expecting either
    // any type of argument or expecting a pointer to a member function of the
    // type provided to the template. Since basic types have no members, the
    // `any argument' variant is selected by the compiler for basic
    // types. These two functions return values having different sizes,
    // allowing the template to determine whether the type is a basic type or
    // not. The enum value 'isBasicType' is initialized accordingly.
   /// For the ReturnType (i.e., the conversion operator's return type the
    // std::conditional template meta programming function is used). For a
    // mutable data type a reference to the Semantic class's data memebr is
    // returned, for an immutable basic data type a copy of the data member's
    // value is returned, otherwise a const & is returned.
//CLASSTRAIT
    struct C2
    {
        char _[2];
    };

    struct C1
    {
        char _;
    };

    template <typename T>
    C1 test(...);

    template <typename T>
    C2 test(void (T::*)());

    template <Tag tg_>
    struct Trait: public TagTrait<tg_>
    {
        typedef typename Trait<tg_>::DataType DataType;
        enum: bool
        {
            isMutable = Trait<tg_>::isMutable,
            isBasicType = sizeof(test<DataType>(0)) == sizeof(C1)
        };

        typedef typename
            std::conditional<
                isMutable,
                    DataType &,
                    typename std::conditional<
                        isBasicType,
                            DataType,
                            DataType const &
                    >::type
            >::type ReturnType;
    };
//=
}

   /// The implementation of the polymorphic semantic value in fact implements
    // a type-safe polymorphic semantic union. This is a non-existing data
    // type in C++, but the parser may handle semantic values as unions: it
    // always knows the actual type of semantic value that's used at a
    // particular point in the grammar, and if not, it can inspect the
    // SemBase's tag fields. Since the parser knows, or can determine what the
    // actual semantic type is, it can always perform a downcast, resulting in
    // a *very* lightweight SemBase base class: there's only a virtual
    // destructor. No other virtual members are required. Downcasting itself
    // is encapsulated in its 'as' member, allowing constructions like
   ///      $1->as<Tag::STRING>()
   /// to downcast the $1 SemBase to a Semantic<Tag::STRING>, and then,
    // usually by implication, to a std::string, using the Semantic's
    // conversion operator.
//SEMBASE
class SemBase
{
    Tag d_tag;

    public:
        SemBase(SemBase const &other) = delete;
        virtual ~SemBase();
        Tag tag() const;

        template <Tag tg_>
        typename Trait<tg_>::ReturnType as() const;

    protected:
        SemBase(Tag tag);
};
//=
inline Tag SemBase::tag() const
{
    return d_tag;
}

inline SemBase::SemBase(Tag tag)
:
    d_tag(tag)
{}


    // The Semantic class template is derived from SemBase. It always defines
    // its data member as mutable (I can't do this under template control, but
    // I could define, e.g., two anonymous structs holding, respectively, a
    // mutable and non-mutable DataType data member, but Semantic isn't doing
    // anything with d_data anyway, so by always declaring d_data as mutable
    // it can be returned from the conversion operator, which itself is a
    // const member.
   /// Again: Semantic is extremely light-weight. Only initialization and
    // conversion to the embedded data member need to be supported.
//SEMANTIC
template <Tag tg_>
class Semantic: public SemBase
{
    typedef typename Trait<tg_>::DataType DataType;
    enum: bool { isMutable = Trait<tg_>::isMutable };

    mutable DataType d_data;

    public:
        typedef typename Trait<tg_>::ReturnType ReturnType;

        Semantic(DataType const &data);
        operator ReturnType() const;
};

template <Tag tg_>
Semantic<tg_>::Semantic(DataType const &data)
:
    SemBase(tg_),
    d_data(data)
{}

template <Tag tg_>
Semantic<tg_>::operator ReturnType() const
{
    return d_data;
}
//=

    // The 'as' member simply performs the required downcast. It is
    // implemented here, since it refers to Semantic<Tag>. Since this class
    // has just been defined, no forward declaration is required anymore.
//AS
template <Tag tg_>
inline   typename Trait<tg_>::ReturnType   SemBase::as() const
{
    return dynamic_cast<Semantic<tg_> const &>(*this);
}
//=

#endif
