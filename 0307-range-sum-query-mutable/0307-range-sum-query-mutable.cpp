struct Node {
	int sum;
	int mn;
	int mx;
	Node(): sum(0), mn(INT_MAX), mx(INT_MIN) {}
	Node(int v): sum(v), mn(v), mx(v) {}
};

class SegmentTree {
	int n;
	vector<Node> st;

	static Node merge(const Node &a, const Node &b) {
		Node res;
		res.sum = a.sum + b.sum;
		res.mn = min(a.mn, b.mn);
		res.mx = max(a.mx, b.mx);
		return res;
	}

	void buildRec(const vector<int> &a, int p, int l, int r) {
		if (l == r) {
			st[p] = Node(a[l]);
			return;
		}
		int m = (l + r) >> 1;
		buildRec(a, p<<1, l, m);
		buildRec(a, p<<1|1, m+1, r);
		st[p] = merge(st[p<<1], st[p<<1|1]);
	}

	void pointAddRec(int p, int l, int r, int idx, int delta) {
		if (l == r) {
			st[p].sum += delta;
			st[p].mn += delta;
			st[p].mx += delta;
			return;
		}
		int m = (l + r) >> 1;
		if (idx <= m) pointAddRec(p<<1, l, m, idx, delta);
		else pointAddRec(p<<1|1, m+1, r, idx, delta);
		st[p] = merge(st[p<<1], st[p<<1|1]);
	}

	void pointSetRec(int p, int l, int r, int idx, int val) {
		if (l == r) {
			st[p] = Node(val);
			return;
		}
		int m = (l + r) >> 1;
		if (idx <= m) pointSetRec(p<<1, l, m, idx, val);
		else pointSetRec(p<<1|1, m+1, r, idx, val);
		st[p] = merge(st[p<<1], st[p<<1|1]);
	}

	Node queryRec(int p, int l, int r, int ql, int qr) const {
		if (ql <= l && r <= qr) return st[p];
		int m = (l + r) >> 1;
		if (qr <= m) return queryRec(p<<1, l, m, ql, qr);
		if (ql > m) return queryRec(p<<1|1, m+1, r, ql, qr);
		Node left = queryRec(p<<1, l, m, ql, qr);
		Node right = queryRec(p<<1|1, m+1, r, ql, qr);
		return merge(left, right);
	}

public:
	SegmentTree() : n(0) {}

	// Build from array (0-indexed)
	void build(vector<int> &a) {
		n = (int)a.size();
		if (n == 0) return;
		st.assign(4*n + 5, Node());
		buildRec(a, 1, 0, n-1);
	}

	// Point add: a[idx] += delta
	void pointAdd(int idx, int delta) {
		if (idx < 0 || idx >= n) return;
		pointAddRec(1, 0, n-1, idx, delta);
	}

	// Point set: a[idx] = val
	void pointSet(int idx, int val) {
		if (idx < 0 || idx >= n) return;
		pointSetRec(1, 0, n-1, idx, val);
	}

	// Range add implemented as repeated point adds (no lazy propagation)
	// Complexity: O((r-l+1) log n)
	void rangeAdd(int l, int r, int delta) {
		if (l > r) return;
		l = max(l, 0); r = min(r, n-1);
		for (int i = l; i <= r; ++i) pointAdd(i, delta);
	}

	// Range query returning Node (sum, min, max)
	Node queryRange(int l, int r) const {
		if (l > r) return Node();
		l = max(l, 0); r = min(r, n-1);
		return queryRec(1, 0, n-1, l, r);
	}

	int querySum(int l, int r) const { return queryRange(l,r).sum; }
	int queryMin(int l, int r) const { return queryRange(l,r).mn; }
	int queryMax(int l, int r) const { return queryRange(l,r).mx; }
};
class NumArray {
public:
SegmentTree st;
    NumArray(vector<int>& nums) {
        st.build(nums);
    }
    
    void update(int index, int val) {
        st.pointSet(index,val);
    }
    
    int sumRange(int left, int right) {
        return st.querySum(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */