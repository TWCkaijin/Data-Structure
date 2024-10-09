#include<iostream> // using input output streaming 
#include<vector>  // using vector 
using namespace std;

class SET{
	public :
		SET(){
			init(); 
		} 
		void init(){   // initialize the array 
			for(int i=0;i<256;i++){
				element[i] = 0;   //make it all 0
			}
		}
		SET(const std::string a){ //constructor that init with a string (read from input)
			init(); // init before any operation
			for(auto ch:a){ 
				element[int(ch)] = 1; // if the specific element exist , change its postion's element  to 1
			}
		}
		SET(const char a[]){  // constructor that init with a series of char , used by init temp object
			init(); // init before any operations
			for(int i = 0; i<256; i++){ 
				if(a[i] > 0){
					element[i] = 1; //if the specific element exist , change its postion to 1 
				}else{
					element[i] = 0; //if the specific element does not exist , change its position's elementto 0
				}
			}
		}
		const char* getElementArr()const{
			return element; // return a char array to past the element array with this method
		}

		SET operator +(const SET& other)const{   // overloading + as Union
			const char* Arrtemp = other.getElementArr(); // get the element array from getElementArr method
			char* result = new char[256]; // create a temporary char array for storaging the result
			for(int i=0;i<256;i++){
				result[i] = element[i]+Arrtemp[i]; // add them together so that if the element exist, the number will be 1 or 2
			}
			SET temp(result); // init with char array , making a temporary object
			return temp; // past the temporary object to the origin 
		};
		
		SET operator -(const SET& other)const{  // overloading - as difference 
			const char* Arrtemp = other.getElementArr(); // get the element array from getElementArr method
			char* result = new char[256]; // create a temporary char array for storaging the result
			for(int i=0;i<256;i++){
				result[i] = element[i]-Arrtemp[i]; // minus them together so that if the element exist int a but not in b , the number will remain 1. However, if the element is in both arr, the number will decrease to zero
			}
			SET temp(result); // init with char array , making a temporary object
			return temp; // past the temporary object to the origin 
		};
		
		SET operator *(const SET& other)const{ // overloading * as intersection
			const char* Arrtemp = other.getElementArr(); // get the element array from getElementArr method
			char* result = new char[256]; // create a temporary char array for storaging the result
			for(int i=0;i<256;i++){
				result[i] = element[i]*Arrtemp[i]; // if both exist , it remains 1, if one of them does not exist , 1*0 equals to zero
			}
			SET temp(result);
			return temp;
		};
		
		string operator >=(const SET& other)const{
			for(int i=0;i<256;i++){
				if(element[i] < other.element[i]){ // if any of the element from B does not exist in A , A does not contain B
					return " does not contain ";  // return the result prompt msg directly
				}
			}
			return " contains "; // else contain , return the result prompt msg directly
		};

		string is_in(char a)const{ 
			if(element[int(a)] == 1){ // find the corresponding position's number is 0 or 1, if 1 , it exist
				return " is in "; //return the prompt msg directly to the origin
			}
			return " is not in "; // else not in , return the prompt msg directly to the origin
		}
		
		friend ostream& operator << (ostream& ofs, const SET& obj){  //overloading the output stream  
			for(int i = 0; i < 256; i++){
				if(obj.element[i] >0){ // if the element exist , load it into the oupt stream
					ofs << char(i);
				}
			}
			return ofs;
		};
		
	private:
		char element[256]; // the main storage to store our element
};

int main(){
    int times=0;
    cin >> times;

    for(int i=0;i<times;i++){
        string x ,y; // declare x and y
        cin >> x >> y; // store the string in x and y

        char t; // 
        cin >> t; // 
		
        SET a(x) , b(y);
        SET c , d;
		c = a+b;
		d = a*b;        
        
        cout << "test case" << i+1 << ": " << endl; // print out test case 
        cout << "A: {" << a << "}" << endl; // print out A set
        cout << "B: {" << b << "}" << endl; // print out B set
        cout << "A+B: {" << c << "}" << endl; // print out the Union of A and B
        cout << "A*B: {" << d << "}" << endl; // print out the intersection of A and B
        cout << "A-B: {" << (a-b) << "}" << endl;  // print out the element that A has but B don't
        cout << "B-A: {" << (b-a) << "}" << endl;  // print out the element that B has but A don't
        cout << "A" << (a>=b) << "B" << endl;   // print out if A contains B
        cout << "B" << (b>=a) << "A" << endl;   // print out if B contains A
        cout << "\'" << t << "\'" << (a.is_in(t))<< "A" << endl; // print if t is int set A
        cout << "\'" << t << "\'" << (b.is_in(t))<< "B" << endl; // print if t is int set B
        cout << endl;
    }
}
