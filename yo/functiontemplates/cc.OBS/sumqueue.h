    template <typename T>
    T sumVector(std::queue<T> &queue)
    {
        T sum();

        while (!queue.empty())
        {
            sum += queue.front();
            queue.pop();
        }
        return sum;
    }
