This project will sample a vending machine's behavior 

This solution was made under the assumption that each purchase is its own transaction and change will be made after each purchase. It is also assumed that the exact coins that are put into the transaction will be returned it the return coins operation is called.
To build the cppunit:
>cd cppunit-1.1.2  
>./configure  
>make  

To build the project with gcc:
>make build

To run the unit tests 
>make test