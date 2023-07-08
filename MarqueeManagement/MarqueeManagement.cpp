#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
struct MarqueeData 
{
	string price;
	string location;
	string marqueeName;
	string perheadPrice;
	string discount;
	int key;
};
struct Node
{
	MarqueeData obj;
	int key;
	Node *left;
	Node *right;
	int height;
};
int max(int, int);
int height(Node*);
Node* newNode(int);
Node *rightRotate(Node*);
Node *leftRotate(Node*);
int getBalance(Node*);
Node* insert(Node*, int, MarqueeData);
void inOrder(Node*);
void inputMarqueeObj(MarqueeData&);
Node* searchByKey(Node*, int);
void displayData(MarqueeData);
Node* searchByPriceRange(Node*, int);
Node* searchByLocation(Node*, string);
void MarqueeDisplay(MarqueeData);
void splashS(sf::RenderWindow &);
void backgroundFunc(string, sf::RenderWindow &);
void InputNameAge(sf::RenderWindow &window);
void text(char letter, int posx, int posy, sf::Color color, sf::RenderWindow & window);
void InputString(sf::RenderWindow &window, int PosX, int PosY, string image, string input);
void text(string letter, int posx, int posy, sf::Color color, sf::RenderWindow & window);
void menu();
int rectX = 0, rectY = 0, letterSize = 50, timeLeft;
int Mx = 255, My = 255, p = 299, c = 299, cmpResult, wrong = 0,posX=0,posY=0;
string playerName;
string words[20], winlossPauseImg, userName;
Node* root = NULL;
int main()
{
	sf::RenderWindow window2(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
	window2.setFramerateLimit(60);
	splashS(window2);
	srand(time(0));

	sf::RenderWindow window3(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
	window3.setFramerateLimit(60);
	InputNameAge(window3);
	return 0;
}
void InputNameAge(sf::RenderWindow &window) {
	cout << "Name page " << endl;
	string nameImg = "img/Name.png";
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {
			case sf::Event::MouseButtonPressed:
				Mx = sf::Mouse::getPosition(window).x;
				My = sf::Mouse::getPosition(window).y;
				//cout << "Mouse position " << Mx << " Mouse position Vertical " << My << endl;
				// cout << Mx << endl;
				if ((Mx > 507 && Mx < 821) && (My > 519 && My < 596)) {
					cout << "Next Button pressed" << endl;
					window.close();
					window.clear();
					menu();
				}
				break;
			case sf::Event::TextEntered:
			{
				if (event.text.unicode < 128) {
					if (event.text.unicode == 13) {
						//cout << "You press Enter" << endl;
						window.close();
						window.clear();
						menu();
						window.display();
					}
					if (event.text.unicode == 8) {
						//cout << "You press BackSpace" << endl;
						userName = " ";
					}
					else {
						userName += event.text.unicode;

					}
					//cout << userName << endl;
					// cout << " " << selectedIndexX << ", " << selectedIndexY << " Selected " << select << endl;

				}
			}
			}
		}
		window.clear();
		backgroundFunc(nameImg, window);
		text(userName, 667, 340, sf::Color::Black, window);
		window.display();
	}
}
void splashS(sf::RenderWindow & window2) {
	while (window2.isOpen()) {
		sf::Event event;
		while (window2.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window2.close();
			}
		}
		window2.clear();
		string img = "img/header.jpg";
		backgroundFunc(img, window2);
		window2.display();
		sf::sleep(sf::milliseconds(5000));
		window2.close();
	}

}




//void InputNameAge(sf::RenderWindow &window) {
//	cout << "Name page " << endl;
//	string nameImg = "img/Name.png";
//	while (window.isOpen()) {
//		sf::Event event;
//		while (window.pollEvent(event)) {
//
//			switch (event.type) {
//			case sf::Event::MouseButtonPressed:
//				Mx = sf::Mouse::getPosition(window).x;
//				My = sf::Mouse::getPosition(window).y;
//				//cout << "Mouse position " << Mx << " Mouse position Vertical " << My << endl;
//				// cout << Mx << endl;
//				if ((Mx > 507 && Mx < 821) && (My > 519 && My < 596)) {
//					cout << "Next Button pressed" << endl;
//					window.close();
//					window.clear();
//					menu();
//				}
//				break;
//			case sf::Event::TextEntered:
//			{
//				if (event.text.unicode < 128) {
//					if (event.text.unicode == 13) {
//						//cout << "You press Enter" << endl;
//						window.close();
//						window.clear();
//						menu();
//						window.display();
//					}
//					if (event.text.unicode == 8) {
//						//cout << "You press BackSpace" << endl;
//						userName = " ";
//					}
//					else {
//						userName += event.text.unicode;
//
//					}
//					//cout << userName << endl;
//					// cout << " " << selectedIndexX << ", " << selectedIndexY << " Selected " << select << endl;
//
//				}
//			}
//			}
//		}
//		window.clear();
//		backgroundFunc(nameImg, window);
//		text(userName, 667, 340, sf::Color::Black, window);
//		window.display();
//	}
//}
//
//


void menu()
{
	string menuImg = "img/marquee.png";
	
	sf::RenderWindow window1(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
	window1.setFramerateLimit(60);
	while (window1.isOpen()) {
		sf::Event event;

		while (window1.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window1.close();
				// case sf::Event::MouseMoved:
			case sf::Event::MouseButtonPressed:
			{
				Mx = sf::Mouse::getPosition(window1).x;
				My = sf::Mouse::getPosition(window1).y;
				cout << " MX " << Mx << " My " << My << endl;
					if ((Mx > 41 && Mx < 541) && (My > 148 && My < 247)) {
						MarqueeData obj;
						int key;
						window1.close();
						letterSize = 55;
						//cout << "Write File" << endl;

						sf::RenderWindow window(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
						window.setFramerateLimit(60);
						string inputMenu = "img/input.png";
						//backgroundFunc(inputMenu, window);
						sf::String playerInput;
						string playerInput1="";
						posX = 0, posY = 0;
					while (window.isOpen()) {
						while (window.pollEvent(event)) {

							switch (event.type) {
							case sf::Event::MouseButtonPressed:
								Mx = sf::Mouse::getPosition(window).x;
								My = sf::Mouse::getPosition(window).y;
								cout << "Mouse position " << Mx << " Mouse position Vertical " << My << endl;
								if ((Mx > 569 && Mx < 1049) && (My > 182 && My < 244) || (posX == 660 &&posY == 187)) {
									posX = 660, posY = 187;
									obj.marqueeName = playerInput1;
									playerInput1 = "";
								}
								if ((Mx > 584 && Mx < 1063) && (My > 289 && My < 348) || (posX == 653 && posY == 293)) {
									posX = 653, posY = 293;
									obj.location = playerInput1;
									playerInput1 = "";
								}
								if ((Mx > 583 && Mx < 1062) && (My > 389 && My < 449) || (posX == 661 && posY == 394)) {
									posX = 661, posY = 394;
									obj.price = playerInput1;
									playerInput1 = "";
								}
								if ((Mx > 583 && Mx < 1066) && (My > 479 && My < 537) || (posX == 663 && posY == 483)) {
									posX = 663, posY = 483;
									obj.discount = playerInput1;
									playerInput1 = "";
								}
								if ((Mx > 583 && Mx < 1066) && (My > 582 && My < 640) || (posX == 668 && posY == 584)) {
									posX = 668, posY = 584;
									obj.perheadPrice = playerInput1;
									playerInput1="";
								}
								if ((Mx > 945 && Mx < 1141) && (My > 692 && My < 739)) {					
									key = rand();
									obj.key = key;
									root = insert(root, key, obj);
									window.close();
									inOrder(root);
									cout<<"Key "<<key << "Name " << obj.marqueeName << " Location " << obj.location << " Price " << obj.price << " Discount " << obj.discount <<"obj.perheadPrice "<< obj.perheadPrice << endl;
									menu();
									/*cout << "position " << Mx << " Mouse position Vertical " << My << endl;
									posX = 670, posY = 506;
									obj.discount = playerInput1;*/
								}

								break;
							case sf::Event::TextEntered:
							{
								if (posX != 0 && posY != 0) {
									if (event.text.unicode < 128) {
										if (event.text.unicode == 13) {
											//cout << "You press Enter" << endl;
											playerInput1 = "";
										}
										if (event.text.unicode == 8) {
											//cout << "You press BackSpace" << endl;
											playerInput1 = "";
										}
										else {
											playerInput1 += event.text.unicode;
										}

										cout << playerInput1 << endl;
										// cout << " " << selectedIndexX << ", " << selectedIndexY << " Selected " << select << endl;

									}
								}
							}
							}

						}
						window.clear();
						backgroundFunc(inputMenu, window);
						text(obj.marqueeName, 660, 187, sf::Color::Black, window);
						text(obj.location, 653, 293, sf::Color::Black, window);
						text(obj.price, 661, 394, sf::Color::Black, window);
						text(obj.discount, 663, 483, sf::Color::Black, window);
						text(obj.perheadPrice, 668, 584, sf::Color::Black, window);
						text(playerInput1, posX, posY, sf::Color::Black, window);
						window.display();
				
					
					}
					}
					else if ((Mx > 678 && Mx < 1181) && (My > 137 && My < 238)) {
						MarqueeData obj;
						int key;
						window1.close();
						letterSize = 55;
						//cout << "Write File" << endl;

						sf::RenderWindow window(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
						window.setFramerateLimit(60);
						string inputMenu = "img/search.png";
						//backgroundFunc(inputMenu, window);
						string playerInput1 = "";
						posX = 0, posY = 0;
						while (window.isOpen()) {
							while (window.pollEvent(event)) {

								switch (event.type) {
								case sf::Event::MouseButtonPressed:
									Mx = sf::Mouse::getPosition(window).x;
									My = sf::Mouse::getPosition(window).y;
									cout << "Mouse position " << Mx << " Mouse position Vertical " << My << endl;
									
									if ((Mx > 476 && Mx < 721) && (My > 693 && My < 742)) {
										cout << "Key Id " << playerInput1 << endl;
										int id = 0;
										stringstream obj(playerInput1);
										obj >> id;
										cout << "Converted Id " << id << endl;
										Node* node = searchByKey(root, id);
										if (node) {
											window.close();
											window.clear();
											displayData(node->obj);
										}
										else {
											window.close();
											window.clear();
											menu();
										}
										//inOrder(root);
										/*cout << "position " << Mx << " Mouse position Vertical " << My << endl;
										posX = 670, posY = 506;
										obj.discount = playerInput1;*/
									}

									break;
								case sf::Event::TextEntered:
								{
										if (event.text.unicode < 128) {
											if (event.text.unicode == 13) {
												playerInput1 = "";
											}
											if (event.text.unicode == 8) {
												playerInput1 = "";
											}
											else {
												playerInput1 += event.text.unicode;
											}

											cout << playerInput1 << endl;
										}
									}
								
								}

							}
							window.clear();
							backgroundFunc(inputMenu, window);
							text(playerInput1, 582, 576, sf::Color::Black, window);
							window.display();
						}
					}

					else if ((Mx > 41 && Mx < 544) && (My > 266 && My < 369)) {
						MarqueeData obj;
						int key;
						window1.close();
						sf::RenderWindow window(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
						window.setFramerateLimit(60);
						string inputMenu = "img/search.png";
						//backgroundFunc(inputMenu, window);
						string playerInput1 = "";
						posX = 0, posY = 0;
						while (window.isOpen()) {
							while (window.pollEvent(event)) {

								switch (event.type) {
								case sf::Event::MouseButtonPressed:
									Mx = sf::Mouse::getPosition(window).x;
									My = sf::Mouse::getPosition(window).y;
									cout << "Mouse position " << Mx << " Mouse position Vertical " << My << endl;

									if ((Mx > 476 && Mx < 721) && (My > 693 && My < 742)) {
										int id = 0;
										stringstream obj(playerInput1);
										obj >> id;
										window.close();
										if (id != 0) {
											Node* node = searchByPriceRange(root, id);
											if (node) {
												window.close();
												window.clear();
												displayData(node->obj);

											}
											else {
												window.close();
												window.clear();
												menu();
											}
										}
										
										else {
											window.close();
											window.clear();
											menu();
										}
									}

									break;
								case sf::Event::TextEntered:
								{
									if (event.text.unicode < 128) {
										if (event.text.unicode == 13) {
											playerInput1 = "";
										}
										if (event.text.unicode == 8) {
											playerInput1 = "";
										}
										else {
											playerInput1 += event.text.unicode;
										}

										cout << playerInput1 << endl;
									}
								}

								}

							}
							window.clear();
							backgroundFunc(inputMenu, window);
							text(playerInput1, 582, 576, sf::Color::Black, window);
							window.display();
						}
					}
					else if ((Mx > 678 && Mx < 1179) && (My > 266 && My < 369)) {
						MarqueeData obj;
						int key;
						window1.close();
						sf::RenderWindow window(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
						window.setFramerateLimit(60);
						string inputMenu = "img/search.png";
						//backgroundFunc(inputMenu, window);
						string playerInput1 = "";
						posX = 0, posY = 0;
						while (window.isOpen()) {
							while (window.pollEvent(event)) {

								switch (event.type) {
								case sf::Event::MouseButtonPressed:
									Mx = sf::Mouse::getPosition(window).x;
									My = sf::Mouse::getPosition(window).y;
									cout << "Mouse position " << Mx << " Mouse position Vertical " << My << endl;

									if ((Mx > 476 && Mx < 721) && (My > 693 && My < 742)) {
									
										window.close();
										if (playerInput1 != "") {
											Node* node = searchByLocation(root, playerInput1);
											if (node) {
												window.close();
												window.clear();
												displayData(node->obj);

											}
											else {
												window.close();
												window.clear();
												menu();
											}
										}

										else {
											window.close();
											window.clear();
											menu();
										}
									}

									break;
								case sf::Event::TextEntered:
								{
									if (event.text.unicode < 128) {
										if (event.text.unicode == 13) {
											playerInput1 = "";
										}
										if (event.text.unicode == 8) {
											playerInput1 = "";
										}
										else {
											playerInput1 += event.text.unicode;
										}

										cout << playerInput1 << endl;
									}
								}

								}

							}
							window.clear();
							backgroundFunc(inputMenu, window);
							text(playerInput1, 582, 576, sf::Color::Black, window);
							window.display();
						}
					}
				else if ((Mx > 260 && Mx < 931) && (My > 608 && My < 700)) {
					window1.close();
				}
			}
			}
		}

		window1.clear();
		// Menu Img

		backgroundFunc(menuImg, window1);
		window1.display();

	}
}


void displayData(MarqueeData obj)
{
	string displayImg = "img/displayData.png";
	sf::RenderWindow window1(sf::VideoMode(1200, 800), "Marquee", sf::Style::None);
	window1.setFramerateLimit(60);
	while (window1.isOpen()) {
		sf::Event event;

		while (window1.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window1.close();
				// case sf::Event::MouseMoved:
			case sf::Event::MouseButtonPressed:
			{
				Mx = sf::Mouse::getPosition(window1).x;
				My = sf::Mouse::getPosition(window1).y;
				cout << " MX " << Mx << " My " << My << endl;
				if ((Mx > 479 && Mx < 721) && (My > 562 && My < 765)) {
					window1.clear();
					window1.close();
					menu();
				}
			}
			}
		}
		window1.clear();
		backgroundFunc(displayImg, window1);
		text(obj.marqueeName, 576, 308, sf::Color::Black, window1);
		text(obj.marqueeName, 632, 345, sf::Color::Black, window1);
		text(obj.location, 627, 386, sf::Color::Black, window1);
		text(obj.price, 570,426, sf::Color::Black, window1);
		text(obj.discount, 538, 466, sf::Color::Black, window1);
		text(obj.perheadPrice, 574, 506, sf::Color::Black, window1);
		window1.display();

	}
}













void backgroundFunc(string img, sf::RenderWindow & window) {
	sf::Texture BackgroundTexture1;
	sf::Sprite background1;
	sf::Vector2u TextureSize1; //Added to store texture size.
	sf::Vector2u WindowSize1; //Added to store window size.
	if (!BackgroundTexture1.loadFromFile(img)) {
		return;
	}
	else {
		TextureSize1 = BackgroundTexture1.getSize(); //Get size of texture.
		WindowSize1 = window.getSize(); //Get size of window.
		float ScaleX = (float)WindowSize1.x / TextureSize1.x;
		float ScaleY = (float)WindowSize1.y / TextureSize1.y; //Calculate scale.
		background1.setTexture(BackgroundTexture1);
		background1.setScale(ScaleX, ScaleY); //Set scale.  
	}
	window.draw(background1);
}
void text(char letter, int posx, int posy, sf::Color color, sf::RenderWindow & window) {
	sf::Font font;
	font.loadFromFile("Sans.ttf");
	sf::Text text1(letter, font);
	text1.setString(letter);
	text1.setCharacterSize(letterSize);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(posx, posy);
	text1.setFillColor(color);
	window.draw(text1);
}
void text(string letter, int posx, int posy, sf::Color color, sf::RenderWindow & window) {
	sf::Font font;
	font.loadFromFile("Sans.ttf");

	sf::Text text1;
	text1.setFont(font);
	text1.setString(letter);
	text1.setCharacterSize(50);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(posx, posy);
	text1.setFillColor(color);
	window.draw(text1);
}
Node* searchByLocation(Node* root, string location) {

	if (root == NULL || root->obj.location == location)

		return root;

	searchByLocation(root->right, location);

	searchByLocation(root->left, location);

}

Node* searchByPriceRange(Node* rootPoint, int price) {
	int objPrice = 0;
	stringstream obj(rootPoint->obj.price);
	obj >> objPrice;
	cout << "Obj Pice " << objPrice << endl;
	if (rootPoint != NULL && objPrice != price && objPrice != NULL)
	{
		searchByPriceRange(rootPoint->left, price);
		searchByPriceRange(rootPoint->right, price);

	}
	return rootPoint;
}

void MarqueeDisplay(MarqueeData obj) {

	cout << "Marquee Name :- " << obj.marqueeName << endl;

	cout << "Marquee Location :- " << obj.location << endl;

	cout << "Marquee Price :- " << obj.price << endl;

	cout << "Perhead Price :- " << obj.perheadPrice << endl;

	cout << "Marquee Discount :- " << obj.discount << endl;

}



Node* searchByKey(Node* root, int key)

{

	if (root == NULL || root->key == key)

		return root;

	if (root->key < key)

		return searchByKey(root->right, key);

	return searchByKey(root->left, key);

}

void inputMarqueeObj(MarqueeData& obj) {

	cout << "Enter Marquee Name " << endl;

	cin >> obj.marqueeName;

	cout << "Enter Marquee Location " << endl;

	cin >> obj.location;

	cout << "Enter Marquee Price " << endl;

	cin >> obj.price;

	cout << "Enter Perhead Price " << endl;

	cin >> obj.perheadPrice;

	cout << "Enter Marquee Discount " << endl;

	cin >> obj.discount;

}

int height(Node *N)

{

	if (N == NULL)

		return 0;

	return N->height;

}

int max(int a, int b)

{

	return (a > b) ? a : b;

}



Node* newNode(int key,MarqueeData obj)

{

	Node* node = new Node();
	node->key = key;
	node->obj = obj;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

	return(node);

}



Node *rightRotate(Node *y)

{

	Node *x = y->left;

	Node *T2 = x->right;

	x->right = y;

	y->left = T2;

	y->height = max(height(y->left),

		height(y->right)) + 1;

	x->height = max(height(x->left),

		height(x->right)) + 1;

	return x;

}

Node *leftRotate(Node *x)

{

	Node *y = x->right;

	Node *T2 = y->left;

	y->left = x;

	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;

	y->height = max(height(y->left), height(y->right)) + 1;

	return y;

}

int getBalance(Node *N)

{

	if (N == NULL)

		return 0;

	return height(N->left) - height(N->right);

}

Node* insert(Node* node, int key,MarqueeData obj)
{
	if (node == NULL)

		return(newNode(key,obj));

	if (key < node->key)

		node->left = insert(node->left, key,obj);

	else if (key > node->key)

		node->right = insert(node->right, key,obj);

	else

		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)

		return rightRotate(node);

	if (balance < -1 && key > node->right->key)

		return leftRotate(node);

	if (balance > 1 && key > node->left->key)

	{

		node->left = leftRotate(node->left);

		return rightRotate(node);

	}

	if (balance < -1 && key < node->right->key)

	{

		node->right = rightRotate(node->right);

		return leftRotate(node);

	}

	return node;

}

void inOrder(Node *root)

{

	if (root != NULL)

	{

		inOrder(root->left);

		cout << " ===========================================================================================================" << endl;

		cout << "Id :- " << root->key << " ";

		MarqueeDisplay(root->obj);

		cout << " ===========================================================================================================" << endl;

		inOrder(root->right);

	}

}