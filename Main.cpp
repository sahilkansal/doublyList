#include<iostream>

using namespace std;

struct node
{
	int info;
	node *forw;
	node *back;
public:
	node(int data, node *f, node *b){
		info = data;
		forw = f;
		back = b;
	}
};

class list{
	node *head;
	node *tail;
public:
	list(){ head = 0; tail = 0; }
	void traverse_back();
	void insert_node(int);
};

void list::insert_node(int data){
	node *ptr = new node(data, 0, 0);
	node *curr = tail;
	if (head == 0){
		head = ptr;
		tail = ptr;
	}
	else{
		tail = ptr;
		tail->back = curr;
		curr->forw = tail;
	}
}

void list::traverse_back(){
	node *curr = tail;
	while (curr != NULL){
		cout << curr->info<<",";
		curr=curr->back;
	}
}

template <typename T1,typename T2>
T1 func(T1 x, T2 y){
	x += y;
	return x;
}

int main(){
	list lt;
	for (int i = 0; i < 5; i++){
		lt.insert_node(i+1);
	}
	lt.traverse_back();
	cout<<func(5, 9)<<endl;
	cout << func(4.5, 5.3)<<endl;
	cin.get();
}
