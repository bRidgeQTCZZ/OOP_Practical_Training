/*
4.练习将实际生活中的事物，抽象成类，并给出类的设计
	(找出数据成员和成员函数并用C++的类表示出来即可)
	1）笔、钢笔
	2）文件、目录
	3）打印机、显示器
	4）太阳、月亮
*/

#include <iostream>
using namespace std;

class Pen {
public:
	Pen(string color, double nibSize) : mColor(color), mNibSize(nibSize) {}
	virtual ~Pen();
	virtual void Write();
protected:
	string mColor;
	double mNibSize;
	double mInk;
};

class FountainPen : public Pen {
public:
	virtual ~FountainPen();
	virtual void Write();
	virtual void AddInk();
};

class Dir;
class File {
public:
	File(string fileName, Dir* dir, double size) : mFileName(fileName), mDir(dir), mSize(size) 
	{
		mDir->AddFile(this);
	}
	void Write();
	void Read();
	void ChangeName(string newName);
	~File()
	{
		mDir->DeleteFile(this);
	}
private:
	string mFileName;
	Dir* mDir;
	double mSize;
};

class Dir {
public:
	Dir(string dirName, Dir* fatherDir = nullptr) : mDirName(dirName), mFatherDir(fatherDir) {}
	void AddFile(File* file);
	void DeleteFile(File* file);
	void ShowFileList();
	~Dir()
	{
		int i = 0;
		while (mFileList[i])
			delete mFileList[i++];
	}
private:
	string mDirName;
	Dir* mFatherDir;
	File* mFileList[1000];
	double mTotalSize;
};

class Printer {

};

class Monitor {

};

class Sun {

};

class Moon {

};

int main()
{
	return 0;
}