#include<iostream>
#include<fstream>
#include<string>

class Node
{
	Node* preNode;
	std::string score;
	std::string name;
	Node* nextNode;

public:

	Node() {
		this->preNode = this;
		this->nextNode = this;
	}

	Node(Node* preNode, std::string score, std::string name, Node* nextNode) {
		this->preNode = preNode;
		this->score = score;
		this->name = name;
		this->nextNode = nextNode;
	}

	std::string getScore() { return this->score; }
	void setScore(std::string score) { this->score = score; }

	std::string getName() { return this->name; }
	void setName(std::string name) { this->name = name; }

	Node* getPreNode() { return this->preNode; }
	void setPreNode(Node* preNode) { this->preNode = preNode; }

	Node* getNextNode() { return this->nextNode; }
	void setNextNode(Node* nextNode) { this->nextNode = nextNode; }
};

class DoublyLinkedList {

	Node* first;
	Node* last;

public :
	DoublyLinkedList() {
		this->first = new Node(NULL, "", "", NULL);
		this->last = new Node(NULL, "", "", NULL);
		first->setNextNode(last);
		last->setPreNode(first);
	}

	//node�Ƃ���Node�̂P����ɐV����Node��ǉ�����
	void add(Node* node, std::string score, std::string name) {

		Node* newNode = new Node(node, score, name, node->getNextNode());
		node->getNextNode()->setPreNode(newNode);
		node->setNextNode(newNode);

	}

	//front��1�����Node��ǉ�����
	void push_front(std::string score, std::string name) {
		add(first, score, name);
	}

	//last�̂P�O����Node��ǉ�����
	void push_back(std::string score, std::string name) {
		add(last->getPreNode(), score, name);
	}

	//DoublyLinkedList�̒��g��擪���珇�ɕW���o�͂ɏo�͂���
	void viewAll() {
		for (Node* i = first->getNextNode(); i != last; i = i->getNextNode()) {
			std::cout << i->getScore() << " , " << i->getName() << std::endl;
		}
	}
};


int main() {

	//�t�@�C���ǂݍ���
	std::string fileName = "Scores.txt";
	std::ifstream readingFile;
	readingFile.open(fileName, std::ios::in);
	std::string readLine;

	DoublyLinkedList list;

	while (std::getline(readingFile, readLine)) {

		std::string score = "", name = "";
		
		//�^�u���O��score��,�^�u������name�֒ǉ�
		for (int i = 0; i < readLine.size(); i++) {
			if (readLine[i] == '\t') {
				while (i < readLine.size()) {
					i++;
					name += readLine[i];
				}
			}
			else {
				score += readLine[i];
			}
		}

		list.push_back(score, name);
	}

	list.viewAll();

	return 0;
}