#include <iostream>
using namespace std;


template <class T>

class DynamicVector {
		T *array; // pointer to the items ָ�����ռ��ָ��
		unsigned mallocSize; // number of allocated spaces ����ռ�Ĵ�С
		unsigned numofItems; // number of items �������Ѿ��洢��Ԫ������
		int virtualZero; // virtual zero ������ʼ�±꣬C������ͨ�������±��Ǵ�0��ʼ�� ����������Կ�����������±��-10��2�ȵ�������ʼ �������������
	public:
		DynamicVector (int );//
		DynamicVector(const DynamicVector &);//
		~DynamicVector();//
		inline void push_back(const T &newItem) {
			if (numofItems < mallocSize) {
				array[numofItems] = newItem;
				numofItems++;
			} else if (numofItems == mallocSize) {
				int i;
				T *arrays = array;
				array = new T[2 * mallocSize + 1];
				mallocSize = 2 * mallocSize + 1;
				for (i = 0; i < numofItems; i++) {
					array[i] = arrays[i];
				}
				array[numofItems] = newItem;
				numofItems++;
				delete [] arrays;
			}
		}
		void push_back(const DynamicVector &t) { //����pushback
			if (numofItems + t.numofItems <= mallocSize) {
				int i;
				for (i = numofItems; i < numofItems + t.numofItems; i++) {
					array[i] = t.array[i - numofItems];
				}
				numofItems = numofItems + t.numofItems;
			} else if (numofItems + t.numofItems > mallocSize) {
				int i;
				T *arrays;
				arrays = array;
				array = new T[2 * mallocSize + 1];
				mallocSize = 2 * mallocSize + 1;
				for (i = 0; i < numofItems; i++) {
					array[i] = arrays[i];
				}
				for (i = numofItems; i < numofItems + t.numofItems; i++) {
					array[i] = t.array[i - numofItems];
				}
				numofItems = numofItems + t.numofItems;
				delete [] arrays;
			}
		}
		T &operator[] (int Vindex);//
		unsigned length() const;
		unsigned capacity() const;
		int firstIndex() const;
		DynamicVector<T> &operator = ( const DynamicVector<T> &anotherDA) {
			if ( this == & anotherDA) {
				return *this;
			}
			delete [] array;
			array = new T[anotherDA.mallocSize];
			mallocSize = anotherDA.mallocSize;
			virtualZero = anotherDA.virtualZero;
			numofItems = anotherDA.numofItems;
			int i;
			for (i = 0; i < anotherDA.mallocSize; i++) {
				array[i] = anotherDA.array[i];
			}
			return *this;
		}
		bool operator == (const  DynamicVector<T> &dv) const;

};
template <class T>

DynamicVector<T>::DynamicVector(int Vindex) {
	array = NULL;
	numofItems = 0;
	mallocSize = 0;
	virtualZero = Vindex;
}
template <class T>

DynamicVector<T>::DynamicVector(const DynamicVector<T> &anotherDA) {
	int i;
	array = new T[anotherDA.mallocSize];
	mallocSize = anotherDA.mallocSize;
	virtualZero = anotherDA.virtualZero;
	numofItems = anotherDA.numofItems;
	for (i = 0; i < mallocSize; i++) {
		array[i] = anotherDA.array[i];
	}
}
template <class T>

DynamicVector<T>::~DynamicVector() {
	delete [] array;
}
template <class T>

T &DynamicVector<T>::operator[] (int Vindex) {
	int _entry = Vindex - virtualZero;
	if (_entry < 0 || _entry >= numofItems) {
		cout << endl << "Out Of Range";
		exit(1);
	}
	return array[_entry];
}
template <class T>

unsigned DynamicVector<T>::length() const {
	return numofItems;
}
template <class T>

unsigned DynamicVector<T>::capacity() const {
	return this->mallocSize;
}
template <class T>

int DynamicVector<T>::firstIndex() const {
	return this->virtualZero;
}

template <class T>

bool DynamicVector<T>::operator == (const DynamicVector<T> &dv) const {
	int i;
	int flag = 1;
	for (i = 0; i < numofItems; i++) {
		if (array[i] != dv.array[i]) {
			flag = 0;
		}
	}
	if (flag == 1 && numofItems == dv.numofItems)
		return true;
	else
		return false;
}





//StudybarCommentBegin
int main()
{
	int i,j;
	DynamicArray<int>  a(20,0);	
	DynamicArray<DynamicArray<int> > b(10,a);
	b[0].resize(30,1);
	b[5].resize(10,5);
	for(i=0;i<10;i++)
	{	cout<<"\n";		
		for(j=0;j<b[i].capacity();j++)
		{	cout<<" "<<b[i][j] ;}
	}
	return 0;
}
//StudybarCommentEnd
