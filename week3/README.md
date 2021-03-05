# Задачи третьей недели

- [Сортировка целых чисел по модулю](https://github.com/qvntz/c-plus-plus-white-belt/blob/main/week3/ex1.cpp)

	В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. Первым числом идёт само число N. Далее следуют ещё N чисел, обозначим их за массив A. Между собой числа разделены пробелом.

	Отсортируйте массив А по модулю и выведите его в стандартный поток.

	### Ограничения
	- 0 <= N <= 1000
	- -1000000 <= A[i] <= 1000000

	  stdin | stdout |
    | :---: | :-----: |
    | 2 -4 3 | 3 -4 |
    | 3 1 -3 2 | 1 2 -3 |

- [Сортировка без учета регистра](https://github.com/qvntz/c-plus-plus-white-belt/blob/main/week3/ex2.cpp)

	В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S. Между собой число и строки разделены пробелом.

	Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный поток вывода.

	### Ограничения

	- 0 <= N <= 1000
	- 1 <= |S| <= 15
	- Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]

	| stdin | stdout |
    | :---: | :-----: |
    | 2 q A | A q |
    | 3 a C b | a b C |

- [Имена и фамилии - 1](https://github.com/qvntz/c-plus-plus-white-belt/blob/main/week3/ex3.cpp)

	Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
	```
	class Person {
	public:
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
	}
	private:
	// приватные поля
	};
	```

	Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

	Гарантируется, что все имена и фамилии непусты.

	Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

	- Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "**Incognito**".
	- Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "**last_name with unknown first name**".
	- Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "**first_name with unknown last name**".

	```
	int main() {
	Person person;
	
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}
	
	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
	
	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
	
	return 0;
	}
	```

	### Вывод
	```
	Incognito
	Polina with unknown last name
	Polina Sergeeva
	Polina Sergeeva
	Appolinaria Sergeeva
	Polina Volkova
	Appolinaria Volkova
	```

- [Имена и фамилии - 2](https://github.com/qvntz/c-plus-plus-white-belt/blob/main/week4/ex1.cpp)

	Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:

	```
	class Person {
	public:
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
	}
	string GetFullNameWithHistory(int year) {
		// получить все имена и фамилии по состоянию на конец года year
	}
	private:
	// приватные поля
	};
	```

	В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.

- [Имена и фамилии - 3](https://github.com/qvntz/c-plus-plus-white-belt/blob/main/week3/ex5.cpp)

	Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.

	При получении на вход года, который меньше года рождения:

	- методы GetFullName и GetFullNameWithHistory должны отдавать ***"No person"***;
	- методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
	Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

	### Пример
	```
	int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
	
	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
	}
	```
	### Вывод
	```
	No person
	Polina Sergeeva
	Appolinaria (Polina) Sergeeva
	Appolinaria (Polina) Ivanova (Sergeeva)
	```
