#include <iostream>
#include <string>
using namespace std;
struct node{
	node *top;

	node *right;
	node *left;
	node *bottom;
	char data;
};

class list{
public:
	list():head(NULL),last(NULL),temp(NULL),position(0),found(false),current(last){
		sf::Texture t;
		t.loadFromFile("w.png");
		sf::Sprite sp;
		sp.setTexture(t);
		window.create(sf::VideoMode(1350,720),"Note Pad");
		curImage.loadFromFile("curImage.png");
		cursor.setTexture(curImage);
		sp.setScale(50,50);
		window.draw(sp);
	}
	
	void add(char x);
	string display();
	void Delete(node *d);
	void setcur(int value);
	void insertmiddle(node*temp,char ch,int pos);
	node *t;
	sf::RenderWindow window;
	
	node *getcurrent(){
		return current;
	}
private:
	int position;
	node *head;
	node *last;
	node *temp;
	node *rp;
	node *current;
	bool found;

	// graphical componenets---------------
	sf::Texture curImage;
	sf::Sprite cursor;
};
void list::setcur(int value)
{
 if(head!=NULL)
 {

if(value==73)//up
{
	
	while((current->top==NULL)&&(current->left!=NULL))
	{
		current=current->left;
	}
	if(current->top!=NULL)
	{current=current->top;
	
	}
	
}

/////////////// down///////////////
else if(value==74){
	
	while((current->bottom==NULL)&&(current->left!=NULL))
	{current=current->left;}
	if(current->bottom!=NULL)
	{current=current->bottom;
	
	}

}
else if(value==71)//left
{
	if(current->left==NULL)
	{found=true;}
if(current->left!=NULL)
{current=current->left;
}

}
else if(value==72)//right
{
	if(current->right!=NULL)
{current=current->right;
	cout<<current->data<<endl;
	}

}////////////////////////////////////////// checking/////////////////////
 }
}
void list:: insertmiddle(node*temp,char ch,int posi)
{
	//node*searchenter=temp;
if(posi<50){
	node*temp2=NULL,*set=NULL;
	node*newnode=new node;
	newnode->data=ch;
	newnode->top=NULL;
	newnode->bottom=NULL;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if((temp->right!=NULL)&&(found==false))
	{
		newnode->left=temp;
	    newnode->right=temp->right;
		temp->right=newnode;
	    newnode->right->left=newnode;
		temp=newnode;
		temp2=temp->right;
	
	}
	else if((temp->left==NULL)&&(found==true))
	{
		newnode->right=temp;
		temp->left=newnode;
		temp=newnode;
		temp2=temp->right;
		if(temp->right==head)
		{head=temp;}

          found==false;	
}
	else
	{
	newnode->left=temp;
	temp->right=newnode;
	temp2=temp->right;
	if((temp->top!=NULL)&&(temp->top->right!=NULL))
	{

		set=temp->top->right;
		temp2->top=set;
		set->bottom=temp2;}
	if((temp->bottom!=NULL)&&(temp->bottom->right!=NULL))
	{
		set=temp->bottom->right;
		temp2->bottom=set;
		set->top=temp2;}

	temp2=NULL;
	temp=NULL;
	}

	while(temp2!=NULL)
	{
		if(temp2->top!=NULL)
		{
			temp2->top->bottom=temp;
			temp->top=temp2->top;}


	if(temp2->bottom!=NULL)
		{
			temp2->bottom->top=temp;
			temp->bottom=temp2->bottom;}
	temp=temp2;
	temp2=temp2->right;}
///////////////////////////////////////////////////////////to set cursor position////////////////////////////////////////	
	if((temp->top!=NULL)&&(temp->top->right!=NULL))
	{
		set=temp->top->right;
		temp->top=set;
		set->bottom=temp;
	}
	else
		temp->top=NULL;
	if((temp->bottom!=NULL)&&(temp->bottom->right!=NULL))
	{
		set=temp->bottom->right;
		temp->bottom=set;
		set->top=temp;
	
	}
	else
		temp->bottom=NULL;
	/////////////////////////////////////////////////////////// to set links when enter is pressed in middle//////

//	insertenter(searchenter);



}



}

void list::add(char  ch){
	
	if(static_cast<int>(ch)!=8){

		if(current!=last)
		{
			
			insertmiddle(current,ch,position);
		
		}
		else
		{
		
		if(head==NULL)
		{
		head= new node;
		head->right=NULL;
		head->left=NULL;
		head->bottom=NULL;
		head->top=NULL;
		head->data=ch;
		last=head;
		rp=head;
		temp=head;
		////////////////////////////
		current=last;
		///////////////////////////
		position++;
		}
		else 
		{
		if(last->data=='\n'|| position==50)
		{
		rp->bottom=new node;
		last=rp->bottom;
		last->top=rp;
		temp=rp;
		rp=rp->bottom;
		last->right=NULL;
		last->bottom=NULL;
		last->left=NULL;
		last->data=ch;
		current=last;
		position=0;
		position++;
		}
		else
		{
			if(temp==rp)
			{
			last->right=new node;
			last->right->left=last;
			last=last->right;
			last->data=ch;
			current=last;
			last->top=NULL;
			last->bottom=NULL;
			last->right=NULL;
			position++;
			}
			else
			{
				last->right=new node;
				last->right->left=last;
				last=last->right;
				last->data=ch;
				current=last;
					if(temp->right==NULL)

					{
						last->top==NULL;
					}
					else
					{
						temp=temp->right;
						last->top=temp;
						temp->bottom=last;
					}
				last->data=ch;
				last->right=NULL;
				last->bottom=NULL;
				position++;
				}
			}
		}
		

		
		
		
		}
}
	
}	
string list::display(){
	sf::Texture t;
	t.loadFromFile("w.png");
	sf::Sprite sp;
	sp.setTexture(t);
	sf::Vector2u cur(0,0);
	sf::Text text;
	window.clear();
	sp.setScale(50,50);
	window.draw(sp);

	text.setColor(sf::Color::Black);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
			cout<<"eroor"<<endl;
	}
	text.setFont(font);
	text.setCharacterSize(36);
	string s,s1;
	node *temp2, *r;
	r=head;
	temp2=head;
	while(temp2!=last){
		if(temp2->right==NULL){
			if(temp2==current){
				cursor.setPosition(cur.x+25,cur.y);
				window.draw(cursor);
			}
			text.setString(temp2->data);
			text.setPosition(cur.x,cur.y);
			window.draw(text);
			temp2=r->bottom;
			r=r->bottom;
			cur.y=cur.y+36;
			cur.x=0;
		}
		else
		{	

			text.setString(temp2->data);
			text.setPosition(cur.x, cur.y);
			cur.x=cur.x+30;
			window.draw(text);
			///////////// break////////////////
			//cout<<current->data<<endl;
			if(temp2==current){
				cursor.setPosition(cur.x+25,cur.y);
				window.draw(cursor);
			}
			temp2=temp2->right;
		}
	}
		if(head!=NULL){
			if(temp2==current){
				cursor.setPosition(cur.x+25,cur.y);
				window.draw(cursor);
			}
			if(last!=NULL){
			text.setString(last->data);
			}
			text.setPosition(cur.x,cur.y);
			window.draw(text);
		}
		window.display();
	return s1;
}
void list::Delete(node *d){
		node *u,*b;
		node *t;
	if(head!=NULL){
		u=d->top;
		b=d->bottom;
		if(d->left==NULL && d->top==NULL){
			d->right->left=NULL;
			head=d->right;
			t=d;
			d=d->right;
			delete t;
			while(d->right!=NULL){
				b->top=d;
				d->bottom=b;
				if(b!=NULL){
					b=b->right;
				}
				d=d->right;
			}
		}
		if(d->left==NULL && d->bottom==NULL){
			d->right->left=NULL;
			t=d;
			d=d->right;
			delete t;
			while(d->right!=NULL){
				u->bottom=d;
				d->top=u;
				if(u!=NULL){
					u=u->right;
				}
				d=d->right;		
			}
			if(u!=NULL){
				if(u->right!=NULL){
					u->right->bottom=NULL;
					d->top=NULL;
					last=d->right;
					if(last==head){
						head==NULL;
					}
				}
			}
		}
		if(d->right==NULL && d->top==NULL){
			if(d->left!=NULL){
				d->left->right=NULL;
			}
			if(d->bottom!=NULL){
				d->bottom->top=NULL;
			}
		}
		if(d->top==NULL && d->left!=NULL && d->right!=NULL){
			d->left->right=d->right;
			d->right->left=d->left;
			t=d;
			d=d->right;
			delete t;
			while(d->right!=NULL){
				if(b!=NULL){
					b->top=d;
				}
				d->bottom=b;
				if(b!=NULL){
					b=b->right;
				}
				d=d->right;
			}
		}
		//---------------check for errors!!!!!!!!!!!!!
		if(d->bottom==NULL && d->right!=NULL && d->left!=NULL){
			d->left->right=d->right;
			d->right->left=d->left;
			t=d;
			d=d->right;
			delete t;
			while(d->right!=NULL){
				d->top=u;
				if(u!=NULL){
					u->bottom=d;
					u=u->right;
					last=d->right;
				}
				d=d->right;
			}
		}
		//--------------------------------------
		if(d->left==NULL && d->right!=NULL && d->top !=NULL && d->bottom!=NULL){
			d->right->left=NULL;
			t=d;
			d=d->right;
			delete t;
			while(d!=NULL){
				d->top=u;
				if(u!=NULL){
					u->bottom=d;
					u=u->right;
				}
				d->bottom=b;
				if(b!=NULL){
					b->top=d;
					b=b->right;
				}
				d=d->right;
			}
		}
		if(d->right==NULL && d->left!=NULL && d->top!=NULL && d->bottom!=NULL){
			d->top->bottom=NULL;
			d->bottom->top=NULL;
			d->left->right=NULL;
			delete d;
			last=last->right;
		}
		if(d->right!=NULL && d->left!=NULL && d->bottom!=NULL && d->top!=NULL){
			d->left->right=d->right;
			d->right->left=d->left;
			t=d;
			d=d->right;
			while(d!=NULL){
				d->top=u;
				d->bottom=b;
				if(u!=NULL){
					u->bottom=d;
					u=u->right;
				}
				if(b!=NULL){
					b->top=d;
					d=d->right;
				}
				d=d->right;
			}
		}
		if(d->right==NULL && d->bottom==NULL && d->left!=NULL){
			
			if(d->top!=NULL){
				d->top->bottom=NULL;
			}
			d->left->right=NULL;
			if(last->left==NULL){
				last=last->top;
			if(last!=NULL){
					while(last->right!=NULL){
						last=last->right;
					}
				}
			}
			if(last!=NULL){
			last=last->left;
			}
		}

	}
}
	

int main()
{	
	int value;
	list l;
	while(l.window.isOpen()){
		sf::Event Event;
		while(l.window.pollEvent(Event)){
			if(Event.type==sf::Event::Closed){
				l.window.close();
			}
			if(Event.key.code!=sf::Keyboard::BackSpace){
				if(Event.type==sf::Event::TextEntered){			
						if(Event.text.unicode==13){
							l.add('\n');
						}else
						{	
							l.add(Event.text.unicode);
						}
					}
			}
			//------------------Handling arrow keys--------------
			if(Event.key.code==sf::Keyboard::Up){
				value=Event.key.code;
				cout<<value;
				l.setcur(value);

				}
			if(Event.key.code==sf::Keyboard::BackSpace){
				cout<<Event.key.code<<endl;
			}
			
			if(Event.key.code==sf::Keyboard::Down){
				value=Event.key.code;
				cout<<value;
		        	l.setcur(value);
					
				}
			
			if(Event.key.code==sf::Keyboard::Left){
				value=Event.key.code;
				cout<<value;
				l.setcur(value);
				}
			
			if(Event.key.code==sf::Keyboard::Right){
				value=Event.key.code;
				cout<<value;
				l.setcur(value);
				}
			if(Event.key.code == sf::Keyboard::BackSpace){
				l.Delete(l.getcurrent());
			}
		}
		l.display();
	}
	system("pause");
	return 0;
}



