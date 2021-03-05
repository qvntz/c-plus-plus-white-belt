- Структруа LectureTitle

	Дана структура LectureTitle:
	```
	struct LectureTitle {
	string specialization;
	string course;
	string week;
	};
	```
	Допишите конструктор и структуры Specialization, Course, Week так, чтобы объект LectureTitle можно было создать с помощью кода 
	```
	LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
	);
	```
	но нельзя было с помощью следующих фрагментов кода:
	```
	LectureTitle title("C++", "White belt", "4th");

	LectureTitle title(string("C++"), string("White belt"), string("4th"));

	LectureTitle title = {"C++", "White belt", "4th"};

	LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

	LectureTitle title(
		Course("White belt"),
		Specialization("C++"),
		Week("4th")
	);

	LectureTitle title(
		Specialization("C++"),
		Week("4th"),
		Course("White belt")
	);
	```


- Обратимая функция с умножением и делением

	Добавьте в класс Function из задачи «Обратимая функция» обработку умножения ('*') и деления ('/'). Гарантируется отсутствие элементарных операций умножения и деления на 0.

- Работа с файлами

	В этом задании вам предстоит написать две небольшие программы. Каждый пункт - отдельная задача, решение отправляйте в поле с соответствующим номером.

	## Часть 1
	Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений. Гарантируется, что содержимое файла input.txt заканчивается переводом строки.

	### Пример
	**input.txt**
	```
	Keep calm
	and
	learn C++
	```
	###stdout
	```
	Keep calm
	and
	learn C++
	```
	## Часть 2
	Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt . Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки. 

	### Пример
	**input.txt**
	```
	Keep calm
	and
	learn C++
	```
	**output.txt**
	```
	Keep calm
	and
	learn C++
	```

- Чтение и вывод таблицы

	В первой строке файла input.txt записаны два числа N и M. Далее в файле находится таблица из N строк и M столбцов, представленная в формате CSV (comma-separated values). Такой формат часто используется для текстового представления таблиц с данными: в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми.  Ваша задача — вывести данные на экран в виде таблицы. Формат таблицы: 

	1)  размер ячейки равен 10, 

	2)  соседние ячейки отделены друг от друга пробелом,

	3)  последняя ячейка в строке НЕ оканчивается пробелом, 

	4)  последняя строка НЕ оканчивается символом перевода строки. Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой из ячеек — целое число.    Пример ввода
	### Ввод
	```
	2 3
	1,2,3
	4,5,6
	```
	### Вывод
	|  |  | |
    | :---: | :-----: | :-----: |
    |1 | 2 | 3 |
    | 4 | 5 | 6 |

- Класс Rational

	В этой задаче вам надо разработать класс для представления рациональных чисел и внедрить его в систему типов языка С++ так, чтобы им можно было пользоваться естественным образом. Задание состоит из нескольких частей. К каждой части приложен файл с заготовкой программы, который имеет следующую структуру 
	```
	#include <iostream>
	using namespace std;

	// Комментарии, которые говорят, что именно нужно реализовать в этой программе

	int main() {
		// Набор юнит-тестов для вашей реализации
		cout << "OK" << endl;
		return 0;
	}
	```
	Вам нужно, ***не меняя тело функции main***, реализовать то, что предложено в комментариях, так, чтобы ваша программа выводила на экран сообщение OK. Функция main содержит ряд юнит-тестов, которые проверяют правильность вашей реализации. Если эти тесты находят ошибку в вашей реализации, то вместо OK программа выведет подсказку о том, что именно работает неправильно.

	Когда ваша программа начнёт выводить OK, можете отправлять свой файл на проверку. Ваша реализация будет тестироваться на другом, более полном наборе тестов. ***То есть, если ваша программа выводит OK, то это не даёт гарантии, что ваша реализация будет принята тестирующей системой***. В случае неудачной посылки тестирующая система также выдаст вам подсказку о том, какая именно часть реализации работает неправильно.

	Внимательно изучите набор юнит-тестов для ***каждой*** заготовки решения. Тесты описывают требования, предъявляемые к вашей реализации, которые могут быть не указаны в условии задач

	На проверку можно отправлять весь файл с вашей реализацией: функцию main удалять из него не нужно.

	## Часть 1
	В первой части Вам надо реализовать класс Rational, который представляет собой рациональное число вида p/q, где p — целое, а q — натуральное и диапазоны возможных значений p, q таковы, что могут быть представлены типом int. При этом, класс Rational должен иметь следующий интерфейс:
	```
	class Rational {
	public:
	Rational();
	Rational(int numerator, int denominator);

	int Numerator() const;
	int Denominator() const;
	};
	```
	Класс Rational должен гарантировать, что p/q — это несократимая дробь. Например, код
	```
	Rational r(4, 6);
	cout << r.Numerator() << '/' << r.Denominator();
	```
	должен выводить «2/3» — именно поэтому мы делаем Rational классом, а не структурой. Структура позволила бы нарушить этот инвариант:  
	```
	struct Rational {
    int numerator, denominator;
	};

	Rational r{2, 3};
	r.numerator = 6; // Нарушен инвариант несократимости
	```
	Список требований, предъявляемых к реализации интерфейса класса Rational:

	1. Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
	2. При конструировании объека класса Rational с параметрами p и q должно выполняться сокращение дроби p/q (здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
	3. Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный знаменатель.
	4. Если дробь p/q положительная, то объект Rational(p, q) должен иметь положительные числитель и знаменатель (обратите внимание на случай Rational(-2, -3)).
	5. Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
	
	***Гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет знаменателя, равного нулю.***

	## Часть 2
	Реализуйте для класса Rational операторы ==, + и - так, чтобы операции с дробями можно было записывать естественным образом. Например, следующий код должен быть валидным:  
	```
	const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
	if (r == Rational(7, 12)) {
	cout << "equal";
	}
	```
	***Гарантируется, что во всех тестах, на которых будет тестироваться ваша реализация, числители и знаменатели ВСЕХ дробей (как исходных, так и получившихся в результате соответствующих арифметических операций) будут укладываться в диапазон типа int.***

	## Часть 3
	Аналогично предыдущей части, реализуйте операторы * и /. Например, следующий код должен быть валидным:  
	```
	const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
	if (r == Rational(2, 3)) {
	cout << "equal";
	}
	```
	***Как и в предыдущем случае, гарантируется, что во всех тестах, на которых будет тестироваться ваша реализация, числители и знаменатели ВСЕХ дробей (как исходных, так и получившихся в результате соответствующих арифметических операций) будут укладываться в диапазон типа int.***

	***Кроме того, гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет выполняться деление на ноль.***

	## Часть 4
	В этой части вам нужно реализовать операторы ввода и вывода для класса Rational. В результате у вас должен работать, например, такой код  
	```
	Rational r;
	cin >> r;
	cout << r;
	```

	## Часть 5
	Наконец, вам нужно реализовать возможность использовать объекты класса Rational в качестве элементов контейнера set и ключей в контейнере map. Пример:
	```
	set<Rational> rationals;
	rationals.insert(Rational(1, 2));
	rationals.insert(Rational(1, 3));

	map<Rational, string> name;
	name[Rational(1, 2)] = "одна вторая";
	```

- Исключение в классе Rational

	Вспомним класс Rational, который мы реализовали в задачах, посвящённых перегрузке операторов. Там специально говорилось, что в тестах объекты класса Rational никогда не создаются с нулевым знаменателем и никогда не выполняется деление на ноль. Настало время избавиться от этого ограничения и научиться обрабатывать нулевой знаменатель и деление на ноль. В этой задаче вам предстоит это сделать. 

	Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение [invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument), если знаменатель  равен нулю. Кроме того, переделайте реализацию оператора деления для класса Rational так, чтобы он выбрасывал исключение [domain_error](https://en.cppreference.com/w/cpp/error/domain_error), если делитель равен нулю.  

	Напомним, что вам надо реализовать интерфейс
	```
	class Rational {
	public:
	Rational();
	Rational(int numerator, int denominator);

	int Numerator() const;
	int Denominator() const;
	};
	```
	и оператор деления для класса Rational
	```
	Rational operator / (const Rational& lhs, const Rational& rhs);
	```
	Так же, как и в задачах на перегрузку операторов, вам будет предложен файл с заготовкой кода. Функция main в этом файле содержит ряд юнит-тестов, которые позволят вам проверить свою реализацию. При проверке вашего решения оно будет тестироваться на более полном наборе тестов, так что успешное прохождение всех юнит-тестов не гарантирует, что ваша реализация будет зачтена.

- Работа с сервером времени

	Вам дана функция string AskTimeServer(), про которую известно следующее:

	- в процессе своей работы она обращается по сети к удалённому серверу, запрашивая текущее время;
	- если обращение к серверу прошло успешно, функция возвращает текущее время в виде строки;
	- если в процессе обращения к серверу возникла сетевая проблема, функция выбрасывает исключение system_error;
	- функция может выбрасывать другие исключения, чтобы сообщить о других проблемах.
	
	Используя функцию AskTimeServer, напишите класс TimeServer со следующим интерфейсом:
	```
	class TimeServer {
	public:
	string GetCurrentTime();
	private:
	string last_fetched_time = "00:00:00";
	};
	```
	Метод GetCurrentTime должен вести себя так:

	- он должен вызвать функцию AskTimeServer, записать её результат в поле last_fetched_time и вернуть значение этого поля;
	- если AskTimeServer выбросила исключение system_error, метод GetCurrentTime должен его поймать и вернуть текущее значение поля last_fetched_time. Таким образом мы скрываем от пользователя сетевые проблемы, возвращая значение, которое было получено при последнем успешном обращении к серверу;
	- если AskTimeServer выбросила другое исключение, метод GetCurrentTime должен пробросить его дальше, потому что в рамках класса TimeServer мы не знаем, как обрабатывать проблемы, не связанные со сбоями сети.
	### Как выполнять задание
	Вам дан файл, содержащий заготовку класса TimeServer. В нём вам надо реализовать метод GetCurrentTime так, как описано выше. Файл содержит пустую функцию AskTimeServer. Для тестирования своей реализации вы можете пробовать добавлять разные команды в её тело:

	- возврат строки;
	- выброс исключения system_error (класс system_error принимает в конструкторе параметр типа error_code, поэтому самый простой способ выбросить это исключение — throw [system_error(error_code())](https://en.cppreference.com/w/cpp/error/system_error);
	- выброс других исключений.