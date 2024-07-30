#include<iostream>
#include<vector>

using namespace std;

struct node {
	int key;
//	vector<node*> child;
	node *parent;
	bool b_ans1;
	bool b_ans2;
};

vector<node> nodes;

int T;
int N;

int ParentCheck(int parent_key,int i) {
	if ( i == 1 )
		nodes[parent_key].b_ans1 = true;
	else
		nodes[parent_key].b_ans2 = true;

	if ( nodes[parent_key].b_ans1 && nodes[parent_key].b_ans2 ) {
		return parent_key;
	}

	if ( nodes[parent_key].parent ) {
		return ParentCheck(nodes[parent_key].parent->key, i);
	}
	else {
		return 0;
	}
}

//void DFS(int now, bool &b_ans1, bool &b_ans2,int &ans1, int& ans2) {
//	for ( node* child_node : nodes[now].child ) {
//		if ( child_node->key == ans1 )b_ans1 = true;
//		if ( child_node->key == ans2 ) b_ans2 = true;
//		
//		DFS(child_node->key, b_ans1, b_ans2, ans1, ans2);
//	}
//}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for ( int i = 0; i < T; i++ ) {
		cin >> N;
		nodes.resize(N + 1);
		for ( int j = 1; j < N + 1; j++ ) {
			nodes[j].key = j;
			nodes[j].parent = nullptr;
			nodes[j].b_ans1 = false;
			nodes[j].b_ans2 = false;

		}
		int ans1, ans2;
		for ( int j = 0; j < N - 1; j++ ) {
			int t1, t2;
			cin >> t1 >> t2;
			nodes[t2].parent = &nodes[t1];
		}
		cin >> ans1 >> ans2;
		ParentCheck(ans1, 1);
		cout << ParentCheck(ans2, 2) << " ";


	}
	cout << endl;
	return 0;
}