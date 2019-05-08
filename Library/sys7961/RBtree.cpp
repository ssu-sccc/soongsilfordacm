
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//using namespace pb_ds;
using namespace __gnu_pbds;
// A red-black tree table storing ints and their order
// statistics. Note that since the tree uses
// tree_order_statistics_node_update as its update policy, then it
// includes its methods by_order and order_of_key.
template <typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename key,typename value>
using ordered_map = tree<key,value,std::less<key>,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
	// Insert some entries into s.
	ordered_set<int> s;
    ordered_map<int,int> map;
    map[1]=1;
    printf("%d\n",map[1]); // 1
    printf("%d\n",map[0]); // default value : 0
    printf("%lu\n",map.order_of_key(2)); // map has 0, 1, so print
	s.insert(12);
	s.insert(505);
	s.insert(30);
	s.insert(1000);
	s.insert(10000);
	s.insert(100);

	// The order of the keys should be: 12, 30, 100, 505, 1000, 10000.
	assert(*s.find_by_order(0) == 12);
	assert(*s.find_by_order(1) == 30);
	assert(*s.find_by_order(2) == 100);
	assert(*s.find_by_order(3) == 505);
	assert(*s.find_by_order(4) == 1000);
	assert(*s.find_by_order(5) == 10000);
	assert(s.find_by_order(6) == s.end());

	// The order of the keys should be: 12, 30, 100, 505, 1000, 10000.
	assert(s.order_of_key(10) == 0);
	assert(s.order_of_key(12) == 0);
	assert(s.order_of_key(15) == 1);
	assert(s.order_of_key(30) == 1);
	assert(s.order_of_key(99) == 2);
	assert(s.order_of_key(100) == 2);
	assert(s.order_of_key(505) == 3);
	assert(s.order_of_key(1000) == 4);
	assert(s.order_of_key(10000) == 5);
	assert(s.order_of_key(9999999) == 6);

	// Erase an entry.
	s.erase(30);

	// The order of the keys should be: 12, 100, 505, 1000, 10000.
	assert(*s.find_by_order(0) == 12);
	assert(*s.find_by_order(1) == 100);
	assert(*s.find_by_order(2) == 505);
	assert(*s.find_by_order(3) == 1000);
	assert(*s.find_by_order(4) == 10000);
	assert(s.find_by_order(5) == s.end());

	// The order of the keys should be: 12, 100, 505, 1000, 10000.
	assert(s.order_of_key(10) == 0);
	assert(s.order_of_key(12) == 0);
	assert(s.order_of_key(100) == 1);
	assert(s.order_of_key(505) == 2);
	assert(s.order_of_key(707) == 3);
	assert(s.order_of_key(1000) == 3);
	assert(s.order_of_key(1001) == 4);
	assert(s.order_of_key(10000) == 4);
	assert(s.order_of_key(100000) == 5);
	assert(s.order_of_key(9999999) == 5);

	return 0;
}
