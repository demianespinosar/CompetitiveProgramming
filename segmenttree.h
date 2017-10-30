#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

template <typename T, class monoid_operator = std::plus<T>, const T identity = T()>
class SegmentTreePointUpdates {
	const monoid_operator op = monoid_operator();

	struct Node {
		int x, y;
		T v;
		std::shared_ptr<Node> l, r;

		Node(int x, int y) : Node(x, y, identity) {};
		Node(int x, int y, const T &v) : x(x), y(y), v(v) {};
	};

	std::shared_ptr<Node> root = nullptr;

	std::shared_ptr<Node> build_st(int x, int y, const std::vector<T> &a){
		if (x == y)
			return std::make_shared<Node>(x, y, a[x]);

		auto node = std::make_shared<Node>(x, y);
		node->l = build_st(x, (x+y)/2, a);
		node->r = build_st((x+y)/2+1, y, a);
		node->v = op(node->l->v, node->r->v);

		return node;
	}

	T query_st(const std::shared_ptr<Node> &node, int l, int r){
		if (node->y < l || r < node->x)
			return identity;

		if (l <= node->x && node->y <= r)
			return node->v;

		return op(
			query_st(node->l, l, r),
			query_st(node->r, l, r)
		);
	}

	void update_st_point(const std::shared_ptr<Node> &node, int i, const T &v){
		if (i < node->x || node->y < i)
			return;

		if (node->x == node->y){
			node->v = v;
			return;
		}

		update_st_point(node->l, i, v);
		update_st_point(node->r, i, v);

		node->v = op(node->l->v, node->r->v);
	}

public:
	SegmentTreePointUpdates(const std::vector<T> &a){
		root = build_st(0, a.size()-1, a);
	}

	T query(int l, int r){
		return query_st(root, l, r);
	}

	void update(int i, T v){
		update_st_point(root, i, v);
	}
};
