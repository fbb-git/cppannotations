    std::string s1;
    std::string s2;
    std::string s3;

    s1 = s2 += s3;                  // 1
    (s2 += s3) + " postfix";        // 2
    s1 = "prefix " + s3;            // 3
    "prefix " + s3 + "postfix";     // 4
    ("prefix " + s3) += "postfix";  // 5
