#include <iostream>
#include <string>
using namespace std;
class Invoice{
	public:
    	Invoice(string number,string description,int quantity,int price)//���캯��
    	:partNumber(number),//��ʼ�������
    	partDescription(description),//��ʼ���������
    	Quantity(quantity),//��ʼ���۳���
    	PricePerItem(price)//��ʼ������
    	{}
 
    	void setPartNumber(string number)//����Ŷ�Ӧ��set��get����
    	{
       		partNumber = number;
    	}
    	string getPartNumber()
    	{
        	return partNumber;
    	}
    	//���������Ӧ��get��set����
    	void setPartDescription(string description)
    	{
        	partDescription = description;
    	}
    	string getPartDescription()
    	{
        	return partDescription;
    	}
    	//��Ʒ�۳�����Ӧ��set��get����
    	void setQuantity(int quantity)
    	{
      		Quantity = quantity;
      		if(Quantity < 0 )
        	{
        		cout<<"\nquantity cannot be negative. quantity set to 0."<<endl;
        	}
    	}
    	int getQuantity()
    	{
    		if(Quantity < 0 )
        	{
        		Quantity=0;
        	}
        	return Quantity;
    	}
    	void setPricePerItem(int price)//��Ʒ���۶�Ӧ��set��get����
    	{
        	PricePerItem = price;
        	if(PricePerItem < 0)
        	{
        		cout<<"\nquantity cannot be negative. quantity set to 0."<<endl;
        		PricePerItem=0;
        	}
    	}
    	int getPricePerItem()
    	{
    		if(PricePerItem < 0)
        	{
        		PricePerItem=0;
        	}
        	return PricePerItem;
    	}
    	
    	//���㲢���ط�Ʊ��
    	int getInvoiceAmount()
    	{
        	if(Quantity < 0 || PricePerItem < 0)
        	{
            	amount = 0;
        	}
        	else
        	{
            	amount = PricePerItem * Quantity;
        	}
        	return amount;
    	}
	private:
    	string partNumber;//�����
    	string partDescription;//�������
    	int Quantity;//��Ʒ�۳���
    	int PricePerItem;//��Ʒ����
    	int amount;//��Ʊ��
};


//StudybarCommentBegin
int main()
{
    // create an Invoice object
    Invoice invoice( "12345", "Hammer", 100, 5 );
    
    // display the invoice data members and calculate the amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    
    // modify the invoice data members
    invoice.setPartNumber( "123456" );
    invoice.setPartDescription( "Saw" );
    invoice.setQuantity( -5 ); // negative quantity, so quantity set to 0
    invoice.setPricePerItem( 10 );
    cout << "\nInvoice data members modified.\n";
    
    // display the modified invoice data members and calculate new amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
