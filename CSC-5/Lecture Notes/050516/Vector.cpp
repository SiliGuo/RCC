#include <vector>
#include <string>
#include <iostream>
using namespace std;

// output_vector
void output_vector(vector<int>);
void output_vector(vector<float>);

int main(int argc, char** argv){
    
    // vector of integers, has no values or elements, it's empty
    vector<int> myVector;
    vector<int> anotherVector(10);
    
    // vector of float
    vector<float> floatValues(50);
    
    cout << "myVector has " << myVector.size() << " elements." << endl;
    cout << "myVector has " << anotherVector.size() << " elements." << endl;
    cout << "myVector has " << floatValues.size() << " elements." << endl;
    
    // initialize anotherVector with 10 values
    anotherVector[0]=1;
    anotherVector[1]=5;
    
    myVector.push_back(7);
    myVector.push_back(10);
    myVector.insert(myVector.begin(),5);
    
    
    // how about a function to output the elements of a vector?
    cout << "Output myVector..." << endl;
    output_vector(myVector);
    
//    cout << "Output myVector..." << endl;
//    output_vector(anotherVector);
//    
//    cout << "Output myVector..." << endl;
//    output_vector(floatValues);
    
    return 0;
}

// output_vector implementation
void output_vector(vector<int> v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << endl;
}

// output_vector implementation
void output_vector(vector<float> v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << endl;
}