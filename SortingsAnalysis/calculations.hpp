template <typename T>
class SortingsAnalyzerClass {

private:
    static unsigned int numOfComparisons;
    static unsigned int numOfAssignments;

public:
    
    SortingsAnalyzerClass(const T& initValue);
    SortingsAnalyzerClass(const SortingsAnalyzerClass& initObj);

    T data;

    bool operator< (const SortingsAnalyzerClass& rightOp);
    SortingsAnalyzerClass& operator= (const SortingsAnalyzerClass& rightOp);
    SortingsAnalyzerClass& operator= (const T& rightOp);

    static unsigned int getNumOfComparisons();
    static unsigned int getNumOfAssignments();
    static void resetNumOfComparisons();
    static void resetNumOfAssignments();
    static void resetStaticMembers();
};

struct Results {

    std::size_t size = 0;
    unsigned int numOfComparisons = 0;
    unsigned int numOfAssignments = 0;
};

void generateArray (SortingsAnalyzerClass<int>* array, std::size_t size);
Results CountActionsDuringSorting (SortingsAnalyzerClass<int>* array, std::size_t size, void (*sort)());
Results* AnalyzeSorting (const std::size_t startSize, const std::size_t step, const std::size_t numOfSteps, const Sorting& sort, Results* arrayOfResults) 
