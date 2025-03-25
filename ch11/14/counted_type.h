struct CountedType
{
    static inline int classCounter = 0; // inline makes cpp implementation file superfluous

    CountedType()
    {
        ++classCounter;
    }

    ~CountedType()
    {
        --classCounter;
    }
};
