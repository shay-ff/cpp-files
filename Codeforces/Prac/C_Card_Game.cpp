template<typename T> using MaxHeap = std::priority_queue<T>;
template<typename T> using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;