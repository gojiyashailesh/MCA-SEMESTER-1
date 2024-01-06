#include<iostream>
#include<string>
#include<fstream>

//student-mca,non mca,local,non-local
//localmca, non-local mca

using namespace std;

class student
{
	
	string	sid;
	string name;
	
	
	public:
		student()
		{
			cout<<"---Student Created with Normal Const------------------------------"<<endl;
		}
		
		virtual void a()=0;
		
		virtual void input()
		{
			cin.ignore();
			cout<<"----------Enter Required Data One By One------------"<<endl;
			cout<<"Enter id:";
			cin>>sid;
			cout<<"name:";
			cin>>name;
		}
		virtual void display()
		{
			cout<<"----------------------"<<endl;
			cout<<"ID:"<<sid<<endl<<"Name:"<<name<<endl;
		}
		virtual ~student()
		{
			cout<<"Student Destroyed"<<endl;
		}
};


class mca :virtual public student
{
	
	int sem;
	string ac_year;
	string course;
	
	public:
		mca()
		{
			cout<<"MCA Student Created"<<endl;
			course="MCA";
		}
		
		
		virtual void input()
		{
			student::input();
			cout<<"Enter Sem:";
			cin>>sem;
			cout<<"year:";
			cin>>ac_year;
		}
		virtual void display()
		{
			student::display();
			cout<<"Sem:"<<sem<<endl<<"Year:"<<ac_year<<endl;
			cout<<"Course:"<<course<<endl;
		}
		virtual void a()
		{
			cout<<0;
		}
		virtual ~mca()
		{
			cout<<"MCA Student Destroyed"<<endl;
		}
};

class nonmca :virtual public student
{
	int sem;
	string ac_year;
	string course;
	public:
		nonmca()
		{
			cout<<"nonMCA Student Created"<<endl;
		}
		
		virtual void input()
		{
			student::input();
			cout<<"Enter Sem: & year & course";
			cin>>sem;
			cin>>ac_year;
			cin>>course;
		}
		virtual void display()
		{
			student::display();
			cout<<"Sem:"<<sem<<endl<<"Year:"<<ac_year<<endl<<"Course:"<<course<<endl;
		}
		virtual void a()
		{
			cout<<0;
		}
		virtual ~nonmca()
		{
			cout<<"nonMCA Student Destroyed"<<endl;
		}
};

class nonlocal :virtual public student
{
	string city;
	public:
		nonlocal()
		{
			cout<<"nonlocal Student Created"<<endl;
		}
		
		virtual void input()
		{
			cout<<"Enter city:";
			cin>>city;
		}
		virtual void display()
		{
			cout<<"City:"<<city<<endl;
		}
		virtual void a()
		{
			cout<<0;
		}
		virtual ~nonlocal()
		{
			cout<<"nonLocal Student Destroyed"<<endl;
		}
};

class local :virtual public student
{
	
	string city;
	public:
		local()
		{
			cout<<"local Student Created"<<endl;
			city="Ahmedabad";
		}
		
		virtual void input()
		{
			student::input();
		}
		virtual void display()
		{
			cout<<"City:"<<city<<endl;
		}
		virtual void a()
		{
			cout<<0;
		}
		virtual ~local()
		{
			cout<<"Local Student Destroyed"<<endl;
		}
};

class localmca:virtual public mca,virtual public local
{
	
	string original_amd;
	
	public:
		localmca():mca(),local()
		{
			cout<<"LOcal Mca Created"<<endl;
		}
		void input()
		{
			mca::input();
			cout<<"Original Ahmedabadi ?";
			cin>>original_amd;
		}
		void display()
		{
			mca::display();
			local::display();
			cout<<"Original Ahmedabadi: "<<original_amd<<endl;
		}
		virtual void a()
		{
			cout<<0;
		}
		~localmca()
		{
			cout<<"\n\n=================Local MCA Student Destroyed=========================================="<<endl;
		}
					
};



int writer(const string filename,int numofobj)
{
	localmca* ptr;
	ptr = new localmca;
	fstream fs;
	
	
	fs.open(filename,ios::out|ios::trunc|ios::binary);
	if(!fs.is_open())
	{
		cout<<"Unable To Open File"<<endl;
		return 0;	
	}
	for(int i=0;i<numofobj;i++)
		{
			ptr->input();
			fs.write((char*)ptr,sizeof(localmca));
		}
		
	fs.close();
	delete ptr;
	return 1;
	
}

int reader(const string filename, int numofobj)
{
	localmca* ptr;
	ptr = new localmca;
	fstream fs;
	
	fs.open(filename,ios::in|ios::binary);
	if(!fs.is_open())
	{
		cout<<"Unable To Open File"<<endl;
		return 0;
	}
	for(int i=0;i<numofobj;i++)
	{
		fs.read((char*)ptr,sizeof(localmca));
		if(fs.eof())
		{
			cout<<"------File Ended--------"<<endl;
			break;
		}
		ptr->display();
	}
	fs.close();
	delete ptr;
	return 1;
}


int main()
{
	string filename="newfile.dat";
	writer(filename,2);
	reader(filename,2);	
	
}