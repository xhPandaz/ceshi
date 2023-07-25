#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class DynamicArray {
	private:
		T *array; //pointer ，一个T类型的指针
		unsigned int mallocSize; //分配空间的大小。
	public:
//Constructors?
		DynamicArray(unsigned length, const T &content) {
			mallocSize = length;
			array = new T[length];
			for(unsigned i=0;i<mallocSize;i++)
			{
				array[i]=content;
			} 
			cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(
			         T) << "=" << this->mallocSize *sizeof(T) << " bytes memory in heap";
		}  // mallocSize=length; 设置每个元素的初始内容是 content；
// Destructors
//
		DynamicArray(const DynamicArray<T> &anotherDA)
		{
    		cout << endl
         		 << "Copy Constructor is called";
    		mallocSize = anotherDA.mallocSize;
    		array = new T[mallocSize];
    		memcpy(array, anotherDA.array, mallocSize * sizeof(T));
		}
		~DynamicArray() {
			cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize *sizeof(
			         T) << " bytes memory in heap";
			if(array!=NULL)
			{
				delete[] array;
			}
			array=NULL;
		}

//
		unsigned int capacity() const {
			return this->mallocSize;
		}
// for the array[i]=someT.
		T &operator[](unsigned int i) {
			return array[i];
		}
//自己定义个operator[] const 重载
		T &operator[](const unsigned int i) const {
			return array[i];
		}
		//Copy Constructor
//
		
//自己定义个?operator =?重载
// 函数内要输出 ?cout<<endl<<"operator = is called";
		DynamicArray<T> &operator= (const DynamicArray<T> &anotherDA ) {
			if (this == &anotherDA)
				return *this;
			mallocSize = anotherDA.mallocSize;
			T *temp = new T[mallocSize];
			memcpy(temp, anotherDA.array, mallocSize * sizeof(T));
			delete[] array;
			array = temp;
			cout << endl << "operator = is called";
			return *this;
		}
};

//StudybarCommentBegin
int main()
{
int length,i;
cin>> length;

DynamicArray<int> iarray(length,-1);

DynamicArray<int> iarray2(iarray),iarray3(iarray2);

cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray3[i] <<" ";
	iarray[i] = i*1.1;	
}
iarray3=iarray2=iarray;
cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray3[i] <<" ";	
}

return 0;
}
//StudybarCommentEnd
