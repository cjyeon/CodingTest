// 실습문제 1: 음악 재생 목록 구현
#include <iostream>
using namespace std;

template <typename T>
struct musiclist_node
{
	T* data;
	musiclist_node* next;
	musiclist_node* prev;

	~musiclist_node()
	{
		delete data;
	}
};

template <typename T>
struct musiclist
{
public:
	using node = musiclist_node<T>;
	using node_ptr = node*;

private:
	node_ptr head;
	size_t n;

public:
	musiclist() : n(0)
	{
		head = new node {NULL, NULL, NULL}; // 모두 NULL로 구성된 기본 노드
		head->next = head;
		head->prev = head;
	}

	size_t size() const
	{
		return n;
	}

	void insert(const T& value)
	{
		node_ptr newNode = new node {new T(value), NULL, NULL};
		n++;

        //순환구조 생성
		auto tmp = head->prev;
		tmp->next = newNode;
		newNode->prev = tmp;
		if (head == tmp)
		{
			tmp->prev = newNode;
			newNode->next = tmp;
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	void erase(const T& value)
	{
		auto cur = head, dummy = head->prev;
		while (cur != dummy)
		{
			if (*(cur->data) == value)
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				if (cur == head)
					head = head->next;
				delete cur;
				n--;
				return;
			}
			cur = cur->next;
		}
	}

	struct musiclist_it
	{
	private:
		node_ptr ptr;

	public:
		musiclist_it(node_ptr p) : ptr(p) {}

		T& operator*()
		{
			return *(ptr->data);
		}

		node_ptr get()
		{
			return ptr;
		}

        //선행 증가
		musiclist_it& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

        //후행 증가
		musiclist_it operator++(int)
		{
			musiclist_it it = *this;
			++(*this);
			return it;
		}

		musiclist_it& operator--()
		{
			ptr = ptr->prev;
			return *this;
		}

		musiclist_it operator--(int)
		{
			musiclist_it it = *this;
			--(*this);
			return it;
		}

		friend bool operator==(const musiclist_it& it1, const musiclist_it& it2)
		{
			return it1.ptr == it2.ptr;
		}

		friend bool operator!=(const musiclist_it& it1, const musiclist_it& it2)
		{
			return it1.ptr != it2.ptr;
		}
	};

	musiclist_it begin() { return musiclist_it {head}; }
    musiclist_it begin() const { return musiclist_it {head}; }
    musiclist_it end() { return musiclist_it {head->prev}; }
	musiclist_it end() const { return musiclist_it {head->prev}; }

	musiclist(const musiclist<T>& other) : musiclist()
	{
		//원형 리스트이기 때문에 역순으로 삽입 가능
		for (const auto& i : other)
			insert(i);
	}

	musiclist(const initializer_list<T>& il) : head(NULL), n(0) {
		for (const auto& i : il)
			insert(i);
	}

	~musiclist()
	{
		while (size()) {
			erase(*(head->data));
		}

		delete head;
	}
};

struct playlist
{
	musiclist<int> list;

	void insert(int song) { list.insert(song); }

	void erase(int song) { list.erase(song); }

	void loopOnce() {
		for (auto& song : list)
			cout << song << " ";
		cout << endl;
	}
};

int main()
{
	playlist pl;
	pl.insert(1);
	pl.insert(2);
	cout << "재생 목록 : ";
	pl.loopOnce();

	playlist pl2 = pl;
	pl2.erase(2);
	pl2.insert(3);
	cout << "두 번째 재생 목록 : ";
	pl2.loopOnce();
}