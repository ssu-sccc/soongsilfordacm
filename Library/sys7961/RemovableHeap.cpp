#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstdlib>

using namespace std;

/* max_heap */
template<typename Ty, typename Pr = less<Ty> >
struct removable_heap
{
        typedef int id_t;
        typedef ptrdiff_t pos_t;

        Pr comparator;
        vector<pair<Ty, id_t>> heap;
        id_t lastid;
        unordered_map<id_t, pos_t> pos;
        removable_heap():lastid(0){}
        /* returns id */
        id_t push(const Ty &val)
        {
                id_t id = lastid++;
                pos_t cur = heap.size();
                heap.emplace_back(move(val), id);
                while(cur > 0) {
                        pos_t par = (cur-1)>>1;
                        /* satisfies heap */
                        if (!comparator(heap[par].first, heap[cur].first))
                                break;
                        swap(heap[par], heap[cur]);
                        pos[heap[cur].second] = cur;
                        cur = par;
                }
                pos[id] = cur;
                return id;
        }
        bool empty() { return heap.empty(); }
        Ty &top() { return heap.front().first; }
        void adjust(pos_t hole)
        {
                for(;;)
                {
                        pos_t par = (hole-1)>>1;
                        pos_t left = hole*2 + 1;
                        pos_t right = hole*2 + 2;
                        pos_t swpind = hole;
                        if (hole > 0 && comparator(heap[par].first, heap[hole].first)){
                                swpind = par;
                        } else if (right < heap.size()) {
                                if (comparator(heap[left].first, heap[right].first)) {
                                        if (comparator(heap[hole].first, heap[right].first)) {
                                                swpind = right;
                                        }
                                } else {
                                        if (comparator(heap[hole].first, heap[left].first)) {
                                                swpind = left;
                                        }
                                }
                        } else if (left < heap.size()) {
                                if (comparator(heap[hole].first, heap[left].first)) {
                                        swpind = left;
                                }
                        }
                        if (swpind == hole) break;
                        swap(heap[swpind], heap[hole]);
                        pos[heap[hole].second] = hole;
                        hole = swpind;
                }
                pos[heap[hole].second] = hole;
        }
        void pop()
        {
                if (empty()) throw runtime_error("pop empty");
                if (heap.size() == 1) {
                        heap.clear();
                        pos.clear();
                        return;
                }
                pos.erase(heap[0].second);
                swap(heap[0], heap.back());
                heap.pop_back();
                adjust(0);
        }
        bool remove(id_t id)
        {
                if (pos.count(id) == 0) return false;
                auto cur = pos[id];
                pos.erase(id);
                if (cur + 1 == heap.size()) {
                        heap.pop_back();
                        return true;
                }
                swap(heap[cur], heap.back());
                heap.pop_back();
                adjust(cur);
        }
        Ty find(id_t id)
        {
                if (pos.count(id) == 0) return Ty();
                return heap[pos[id]];
        }
        void modify(id_t id, const Ty &newValue)
        {
                if (pos.count(id) == 0) throw runtime_error("invalid id");
                auto cur = pos[id];
                heap[cur].first = move(newValue);
                adjust(cur);
        }
};

