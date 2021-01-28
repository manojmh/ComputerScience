/**
Solution to Bounded Buffer or producer consumer problem 
**/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	size_t size = 1024;
	char data[1024];
};
std::mutex mu;
std::condition_variable cv;
std::vector<Node> v(10);
int i = 0, j = 0;
bool eof = false;

void producer() {
	ifstream ifs("test.mp4", std::ios::binary);
	while(true) {
		std::unique_lock<mutex> lock(mu);
		cv.wait(lock, [](){ return ((i-j) != v.size()); });
		Node node;
		ifs.read(node.data, 1024);
		cout << ".";
		if ( (ifs.rdstate() & std::ifstream::eofbit ) != 0 ) {
			cout << "eof reached\n";
			node.size = ifs.gcount();
			v[(i++)%v.size()] = node;
			cv.notify_one();
			eof = true;
			break;
		}
		v[(i++)%v.size()] = node;
		cv.notify_one();
	}
	cout << "Completed reading\n";
	ifs.close();
}

void consumer() {
	ofstream ofs("out.mp4", std::ios::binary);
	while(true) {
		if(eof == true && i<=j)
			break;
		std::unique_lock<mutex> lock(mu);
		cv.wait(lock, []() { return i!=j; });
		ofs.write(v[j%v.size()].data, v[j%v.size()].size);
		cout << "_";
		j++;
		cv.notify_one();
	}
	cout << "Completed writing\n";
	ofs.close();
}

int main() {
	std::thread t1(producer);
	std::thread t2(consumer);
	t1.join();
	t2.join();
	return 0;
}
