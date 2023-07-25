#include <iostream>
#include <string>
using namespace std;
class Invoice{
	public:
    	Invoice(string number,string description,int quantity,int price)//构造函数
    	:partNumber(number),//初始化零件号
    	partDescription(description),//初始化零件描述
    	Quantity(quantity),//初始化售出量
    	PricePerItem(price)//初始化单价
    	{}
 
    	void setPartNumber(string number)//零件号对应的set和get函数
    	{
       		partNumber = number;
    	}
    	string getPartNumber()
    	{
        	return partNumber;
    	}
    	//零件描述对应的get和set函数
    	void setPartDescription(string description)
    	{
        	partDescription = description;
    	}
    	string getPartDescription()
    	{
        	return partDescription;
    	}
    	//商品售出量对应的set和get函数
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
    	void setPricePerItem(int price)//商品单价对应的set和get函数
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
    	
    	//计算并返回发票额
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
    	string partNumber;//零件号
    	string partDescription;//零件描述
    	int Quantity;//商品售出量
    	int PricePerItem;//商品单价
    	int amount;//发票额
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
