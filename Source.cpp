#include <iostream>
#include <string>

using namespace std;


string BinToHex();
int BinToDec();
string DecToBinary();
string DecToBinary(unsigned int a);
string DecToHex();
string DecToHex(unsigned int a);
int HexToDec();
string HexToBin();
void MainMenu();
void Converter();
void Calculator();
char getOperator();


int main()
{
	while (true)
	{
		MainMenu();
	}

	return 0;
}

void Calculator()
{
	bool flag = true;
	while (flag)
	{
		cout << "\t\t<CALCULATOR> " << endl;
		cout << "================================================" << endl;
		cout << "Enter the base: " << endl;
		cout << "1) Binary" << endl;
		cout << "2) Decimal" << endl;
		cout << "3) Hexademical" << endl;
		cout << "0) Exit" << endl;
		cout << "================================================" << endl;
		int answer = -1;
		bool cinFail = true;
		while (answer < 0 || answer > 3 || cinFail == true)
		{
			cout << "Enter the number: ";
			cin >> answer;
			cinFail = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (answer == 0)
		{
			flag = false;
			break;
		}
		char operation = getOperator();
		int firstNum, secNum;
		switch (operation)
		{
		case('+'):
			switch (answer)
			{
			case(1):
				cout << "Your SUM is: " << DecToBinary(BinToDec() + BinToDec()) << endl;
				break;
			case(2):
				cinFail = true;
				while (cinFail)
				{
					cout << "Enter your first number: " << endl;
					cin >> firstNum;
					cinFail = cin.fail();
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (!cinFail)
					{
						cout << "Enter your second number: " << endl;
						cin >> secNum;
						cinFail = cin.fail();
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << "Your SUM is: " << firstNum + secNum << endl;
				break;
			case(3):
				cout << "Your SUM is: " << DecToHex(HexToDec() + HexToDec()) << endl;
				break;
			default:
				break;
			}
			break;
		case('-'):
			switch (answer)
			{
			case(1):
				firstNum = BinToDec();
				secNum = BinToDec();
				if (firstNum >= secNum)
				{
					cout << "Your SUBSTRACTION is: " << DecToBinary(firstNum - secNum) << endl;
				}
				else
				{
					cout << "Your SUBSTRACTION is: -" << DecToBinary(secNum - firstNum) << endl;
				}
				break;
			case(2):
				cinFail = true;
				while (cinFail)
				{
					cout << "Enter your first number: " << endl;
					cin >> firstNum;
					cinFail = cin.fail();
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (!cinFail)
					{
						cout << "Enter your second number: " << endl;
						cin >> secNum;
						cinFail = cin.fail();
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << "Your SUBSTRACTION is: " << firstNum - secNum << endl;
				break;
			case(3):
				firstNum = HexToDec();
				secNum = HexToDec();
				if (firstNum >= secNum)
				{
					cout << "Your SUBSTRACTION is: " << DecToHex(firstNum - secNum) << endl;
				}
				else
				{
					cout << "Your SUBSTRACTION is: -" << DecToHex(secNum - firstNum) << endl;
				}
				break;
			default:
				break;
			}
			break;
		case('*'):
			switch (answer)
			{
			case(1):
				cout << "Your MULTIPLICATION is: " << DecToBinary(BinToDec() * BinToDec()) << endl;
				break;
			case(2):
				cinFail = true;
				while (cinFail)
				{
					cout << "Enter your first number: " << endl;
					cin >> firstNum;
					cinFail = cin.fail();
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (!cinFail)
					{
						cout << "Enter your second number: " << endl;
						cin >> secNum;
						cinFail = cin.fail();
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << "Your MULTIPLICATION is: " << firstNum * secNum << endl;
				break;
			case(3):
				cout << "Your MULTIPLICATION is: " << DecToHex(HexToDec() * HexToDec()) << endl;
				break;
			default:
				break;
			}
			break;
		case('/'):
			switch (answer)
			{
			case(1):
				cout << "Your DIVISION is: " << DecToBinary(BinToDec() / BinToDec()) << endl;
				break;
			case(2):
				cinFail = true;
				while (cinFail)
				{
					cout << "Enter your first number: " << endl;
					cin >> firstNum;
					cinFail = cin.fail();
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (!cinFail)
					{
						cout << "Enter your second number: " << endl;
						cin >> secNum;
						cinFail = cin.fail();
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << "Your DIVISION is: " << firstNum / secNum << endl;
				break;
			case(3):
				cout << "Your DIVISION is: " << DecToHex(HexToDec() / HexToDec()) << endl;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

char getOperator()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
	{
		cout << "Enter the arithmetic operation" << endl;
		cout << "Enter one of the following: +, -, *, or / " << endl;
		char sm;
		cin >> sm;

		// Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

		std::cin.ignore(32767, '\n'); // удаляем лишний балласт

		// Выполняем проверку пользовательского ввода
		if (sm == '+' || sm == '-' || sm == '*' || sm == '/')
			return sm; // возвращаем обратно в caller
		else // в противном случае, сообщаем пользователю что что-то пошло не так
			cout << "Oops, that input is invalid.  Please try again.\n";
	}
}



string DecToBinary()
{
	unsigned int a = 0;
	bool cinFail = true;
	while (a < 0  || cinFail == true)
	{
		cout << "Enter your positive number : " << endl;
		cin >> a;
		cinFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	string biNum;
	if (a == 0)
	{
		biNum = "0";
	}
	else
	{
		while (a > 0)
		{
			int b = a;
			a >>= 1;  // Производим побитовый сдвиг (равносильное делению на 2)
			// Выполняем логическое ИЛИ и смотрим младший бит (был ли он равен 1 или 0)
			((b | 1) == b) ? biNum.insert(0, "1") : biNum.insert(0, "0");
		}
	}
	return biNum;
}
string DecToBinary(unsigned int a)
{
	string biNum;
	if (a == 0)
	{
		biNum = "0";
	}
	else
	{
		while (a > 0)
		{
			int b = a;
			a >>= 1;  // Производим побитовый сдвиг (равносильное делению на 2)
			// Выполняем логическое ИЛИ и смотрим младший бит (был ли он равен 1 или 0)
			((b | 1) == b) ? biNum.insert(0, "1") : biNum.insert(0, "0");
		}
	}
	return biNum;
}


string DecToHex()
{
	unsigned int a  = 0;
	bool cinFail = true;
	while (a < 0 || cinFail == true)
	{
		cout << "Enter your positive number : " << endl;
		cin >> a;
		cinFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	string hexNum;
	if (a == 0)
	{
		hexNum = "0";
	}
	else
	{
		while (a != 0)
		{
			int b = a;
			a >>= 4; // Сдвиг на 4 = делению на 16
			// Дальше смотрим на остаток и заносим его в строчку
			for (size_t i = 0; i < 16; i++)
			{
				b -= a;
			}
			switch (b)
			{
			case(0):
				hexNum.insert(0, "0");
				break;
			case(1):
				hexNum.insert(0, "1");
				break;
			case(2):
				hexNum.insert(0, "2");
				break;
			case(3):
				hexNum.insert(0, "3");
				break;
			case(4):
				hexNum.insert(0, "4");
				break;
			case(5):
				hexNum.insert(0, "5");
				break;
			case(6):
				hexNum.insert(0, "6");
				break;
			case(7):
				hexNum.insert(0, "7");
				break;
			case(8):
				hexNum.insert(0, "8");
				break;
			case(9):
				hexNum.insert(0, "9");
				break;
			case(10):
				hexNum.insert(0, "A");
				break;
			case(11):
				hexNum.insert(0, "B");
				break;
			case(12):
				hexNum.insert(0, "C");
				break;
			case(13):
				hexNum.insert(0, "D");
				break;
			case(14):
				hexNum.insert(0, "E");
				break;
			case(15):
				hexNum.insert(0, "F");
				break;
			default:
				break;
			}
		}
	}
	return hexNum;
}
string DecToHex(unsigned int a)
{
	string hexNum;
	if (a == 0)
	{
		hexNum = "0";
	}
	else
	{
		while (a != 0)
		{
			int b = a;
			a >>= 4; // Сдвиг на 4 = делению на 16
			// Дальше смотрим на остаток и заносим его в строчку
			for (size_t i = 0; i < 16; i++)
			{
				b -= a;
			}
			switch (b)
			{
			case(0):
				hexNum.insert(0, "0");
				break;
			case(1):
				hexNum.insert(0, "1");
				break;
			case(2):
				hexNum.insert(0, "2");
				break;
			case(3):
				hexNum.insert(0, "3");
				break;
			case(4):
				hexNum.insert(0, "4");
				break;
			case(5):
				hexNum.insert(0, "5");
				break;
			case(6):
				hexNum.insert(0, "6");
				break;
			case(7):
				hexNum.insert(0, "7");
				break;
			case(8):
				hexNum.insert(0, "8");
				break;
			case(9):
				hexNum.insert(0, "9");
				break;
			case(10):
				hexNum.insert(0, "A");
				break;
			case(11):
				hexNum.insert(0, "B");
				break;
			case(12):
				hexNum.insert(0, "C");
				break;
			case(13):
				hexNum.insert(0, "D");
				break;
			case(14):
				hexNum.insert(0, "E");
				break;
			case(15):
				hexNum.insert(0, "F");
				break;
			default:
				break;
			}
		}
	}
	return hexNum;
}


int BinToDec()
{
	string biNum;
	cout << "Enter your positive binary number: " << endl;
	cin >> biNum;
	int number = 0;
	auto it = biNum.end();
	for (size_t i = 0; it != biNum.begin(); i++)
	{
		// Двигаемся от младшего разряда к старшему, и смотрим на значение бита
		if (*--it == '1')
		{
			number += 1 << i; // После чего добавляем значение бита умноженное на степень этого бита (через битовый сдвиг)
		}
	}
	return number;
}
int HexToDec()
{
	string hexNum;
	cout << "Enter your positive hexademical number: " << endl;
	cin >> hexNum;
	//Переводим строку в верхний регистр, чтобы не было ошибок
	for (auto& c : hexNum) c = toupper(c);
	int number = 0;
	auto it = hexNum.end();
	for (size_t i = 0; it != hexNum.begin(); i += 4)
	{
		unsigned int x;
		// Двигаемся от младшего разряда к старшему, и смотрим на значение бита
		switch (*--it)
		{
		case('0'):
			x = 0;
			break;
		case('1'):
			x = 1;
			break;
		case('2'):
			x = 2;
			break;
		case('3'):
			x = 3;
			break;
		case('4'):
			x = 4;
			break;
		case('5'):
			x = 5;
			break;
		case('6'):
			x = 6;
			break;
		case('7'):
			x = 7;
			break;
		case('8'):
			x = 8;
			break;
		case('9'):
			x = 9;
			break;
		case('A'):
			x = 10;
			break;
		case('B'):
			x = 11;
			break;
		case('C'):
			x = 12;
			break;
		case('D'):
			x = 13;
			break;
		case('E'):
			x = 14;
			break;
		case('F'):
			x = 15;
			break;
		default:
			break;
		}

		number += (x << i); // После чего добавляем значение бита умноженное на степень этого бита (через битовый сдвиг)

	}
	return number;
}

void MainMenu()
{
	cout << "\t\t<MAIN MENU>" << endl;
	cout << "================================================" << endl;
	cout << "Choose the action: " << endl;
	cout << "1) Converter" << endl;
	cout << "2) Calculator" << endl;
	cout << "0) Exit" << endl;
	cout << "================================================" << endl;
	int answer = -1;
	bool cinFail = true;
	while (answer < 0 || answer > 2 || cinFail == true)
	{
		cout << "Enter the number: ";
		cin >> answer;
		cinFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	switch (answer)
	{
	case(0):
		exit(0);
	case(1):
		Converter();
		break;
	case(2):
		Calculator();
		break;
	default:
		break;
	}
}
void Converter()
{
	bool flag = true;
	while (flag)
	{
		cout << "\t\t<CONVERTER> " << endl;
		cout << "================================================" << endl;
		cout << "1) From Binary to Decimal" << endl;
		cout << "2) From Binary to Hexademical" << endl;
		cout << "3) From Decimal to Binary" << endl;
		cout << "4) From Decimal to Hexademical" << endl;
		cout << "5) From Hexademical to Binary" << endl;
		cout << "6) From Hexademical to Decimal" << endl;
		cout << "0) Exit" << endl;
		cout << "================================================" << endl;
		int answer = -1;
		bool cinFail = true;
		while (answer < 0 || answer > 6 || cinFail == true)
		{
			cout << "Enter the number: ";
			cin >> answer;
			cinFail = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (answer)
		{
		case(1):
			cout << "Your number in decimal system: \n" << BinToDec() << endl;
			break;
		case(2):
			cout << "Your number in hexadmical system: \n" << BinToHex() << endl;
			break;
		case(3):
			cout << "Your number in binary system: \n" << DecToBinary() << endl;
			break;
		case(4):
			cout << "Your number in hexadmical system: \n" << DecToHex() << endl;
			break;
		case(5):
			cout << "Your number in binary system: \n" << HexToBin() << endl;
			break;
		case(6):
			cout << "Your number in decimal system: \n" << HexToDec() << endl;
			break;
		case(0):
			flag = false;
			break;
		default:
			break;
		}
	}
}


string BinToHex()
{
	return DecToHex(BinToDec());
}
string HexToBin() 
{
	return DecToBinary(HexToDec());
}