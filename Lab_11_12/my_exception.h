#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyException {
private:
	vector<string> erori;

public:
	MyException(vector<string> erori_)
	{
		for (int i = 0; i < erori_.size(); i++)
			this->erori.push_back(erori_[i]);
	}
	~MyException() = default;
	void printErori()
	{
		for (int i = 0; i < erori.size(); i++)
			cout << "\t" << erori[i] << endl;
	}
};