#include <iostream>
#include <string>
using namespace std;

class TEL
{
 friend class TList;
private:
 char data;
 TEL* next;
public:
 TEL(char d = '\0', TEL* n = nullptr) : data(d), next(n) {}

};

class TList
{
public:
 TList() : head(nullptr), tail(nullptr) {}
 ~TList() { destroy(); }
 void create();
 void output() const;
 void remove(char value);
 void replace();
 void destroy();
 bool isEmpty() const { return head == nullptr; }
private:
 TEL* head;
 TEL* tail;
};

void TList::create()
{
 cout << "Введите символы (окончание ввода - точка): ";
 string str;
 getline(cin, str, '.');

 destroy();

 for (char ch : str)
 {
  if (ch == '\n' || ch == ' ')
   continue;
  TEL* newNode = new TEL(ch);
  if (isEmpty())
  {
   head = tail = newNode;
   newNode->next = head;
  }
  else
  {
   tail->next = newNode;
   tail = newNode;
   tail->next = head;
  }
 }
}

void TList::output() const
{
 if (isEmpty())
 {
  cout << "Список пуст." << endl;
  return;
 }
 TEL* current = head;
 do
 {
  cout << current->data << " ";
  current = current->next;
 } while (current != head);
 cout << endl;
}

void TList::remove(char value) {
 if (isEmpty()) {
  cout << "Список пуст. Удалять нечего." << endl;
  return;
 }

 TEL* current = head;
 TEL* prev = tail;
 bool deleted = false;
 int count = 0;
 TEL* temp = head;
 do {
  count++;
  temp = temp->next;
 } while (temp != head);
 for (int i = 0; i < count; ) {
  if (current->data == value) {
   deleted = true;
   TEL* nodeToDelete = current;

   if (head == tail) { 
    delete nodeToDelete;
    head = tail = nullptr;
    cout << "Удалено последнее вхождение '" << value << "'" << endl;
    return;
   }
   else if (current == head) { 
    head = head->next;
    tail->next = head;
    current = head;
    prev = tail;
   }
   else if (current == tail) { 
    prev->next = head;
    tail = prev;
    current = head;
   }
   else { 
    prev->next = current->next;
    current = current->next;
   }

   delete nodeToDelete;
   count--; 
  }
  else {
   prev = current;
   current = current->next;
   i++;
  }
 }

 if (!deleted) {
  cout << "Элемент '" << value << "' не найден в списке." << endl;
 }
 else {
  cout << "Все вхождения '" << value << "' удалены." << endl;
 }
}

void TList :: replace()
{
 if (isEmpty())
 {
  cout << "Список пуст." << endl;
  return;
 }
 else
 {
  cout << "Все цифры были заменены на точки." << endl;
  TEL* current = head;
  do
  {
   if (isdigit(current->data))
    current->data = '.';
   current = current->next;
  } while (current != head);
 }
}

void TList::destroy()
{
 if (isEmpty())

  return;
 TEL* current = head;
 TEL* nextTel;
 do
 {
  nextTel = current->next;
  delete current;
  current = nextTel;
 } while (current != head);
 head = tail = nullptr;
}

void showMenu()
{
 cout << endl << ">МЕНЮ<" << endl;
 cout << "===========================" << endl;
 cout << "1. Создать список символов." << endl;
 cout << "2. Распечатать список." << endl;
 cout << "3. Удалить элемент с заданным значением." << endl;
 cout << "4. Заменить все цифры точками." << endl;
 cout << "5. Уничтожить список." << endl;
 cout << "6. Выход." << endl;
 cout << "===========================" << endl;
 cout << ">>Выберите опцию: ";
}

int main()
{
 setlocale(LC_ALL, "RUS");
 cout << "ЛАБОРАТОРНАЯ РАБОТА 20: СПИСКИ." << endl;
 cout << "================================" << endl;

 TList list;
 int choice;
 char value;

 do
 {
  showMenu();
  cin >> choice;
  cin.ignore();

  cout << "===========================" << endl << endl;

  switch (choice)
  {
  case 1: 
   list.create();
   break;
  case 2:
   list.output();
   break;
  case 3:
   cout << "Введите значение для удаления: ";
   cin >> value;
   list.remove(value);
   break;
  case 4:
   list.replace();
   break;
  case 5:
   cout << "Список уничтожен." << endl;
   list.destroy();
   break;
  case 6:
   cout << "Выход из программы." << endl;
   break;
  default:
   cout << "Такой опции не существует." << endl;
  }
 } while (choice != 6);
 return 0;
}
#include <iostream>
#include <string>
using namespace std;

class TEL {
    friend class TList;
private:
    char data;
    TEL* next;
public:
    TEL(char d = '\0', TEL* n = nullptr) : data(d), next(n) {}
};

class TList {
private:
    TEL* head;  // Указатель на первый элемент
public:
    TList() : head(nullptr) {}
    ~TList() { destroy(); }
    
    void create();
    void output() const;
    void remove(char value);
    void replace();
    void destroy();
    bool isEmpty() const { return head == nullptr; }
};

void TList::create() {
    destroy();
    cout << "Введите символы (окончание ввода - точка): ";
    string str;
    getline(cin, str, '.');

    if (str.empty()) return;

    // Создаем первый элемент
    head = new TEL(str[0]);
    head->next = head;  // Замыкаем кольцо

    TEL* last = head;
    for (size_t i = 1; i < str.size(); ++i) {
        char ch = str[i];
        if (ch == '\n' || ch == ' ') continue;
        
        TEL* newNode = new TEL(ch, head);
        last->next = newNode;
        last = newNode;
    }
}

void TList::output() const {
    if (isEmpty()) {
        cout << "Список пуст." << endl;
        return;
    }

    TEL* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void TList::remove(char value) {
    if (isEmpty()) {
        cout << "Список пуст." << endl;
        return;
    }

    bool deleted = false;
    TEL* current = head;
    TEL* prev = head;
    
    // Находим предыдущий элемент перед head
    while (prev->next != head) {
        prev = prev->next;
    }

    int count = 0;
    TEL* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    for (int i = 0; i < count; ) {
        if (current->data == value) {
            deleted = true;
            
            if (current->next == current) {  // Единственный элемент
                delete current;
                head = nullptr;
                cout << "Удалено последнее вхождение '" << value << "'" << endl;
                return;
            }
            
            prev->next = current->next;
            if (current == head) {
                head = current->next;
            }
            
            TEL* toDelete = current;
            current = current->next;
            delete toDelete;
            count--;
            continue;
        }
        
        prev = current;
        current = current->next;
        i++;
    }

    if (!deleted) {
        cout << "Элемент '" << value << "' не найден." << endl;
    } else {
        cout << "Все вхождения '" << value << "' удалены." << endl;
    }
}

void TList::replace() {
    if (isEmpty()) {
        cout << "Список пуст." << endl;
        return;
    }

    TEL* current = head;
    do {
        if (isdigit(current->data)) {
            current->data = '.';
        }
        current = current->next;
    } while (current != head);
    
    cout << "Все цифры заменены на точки." << endl;
}

void TList::destroy() {
    if (isEmpty()) return;
    
    TEL* current = head->next;
    while (current != head) {
        TEL* next = current->next;
        delete current;
        current = next;
    }
    delete head;
    head = nullptr;
}
void showMenu()
{
 cout << endl << ">МЕНЮ<" << endl;
 cout << "===========================" << endl;
 cout << "1. Создать список символов." << endl;
 cout << "2. Распечатать список." << endl;
 cout << "3. Удалить элемент с заданным значением." << endl;
 cout << "4. Заменить все цифры точками." << endl;
 cout << "5. Уничтожить список." << endl;
 cout << "6. Выход." << endl;
 cout << "===========================" << endl;
 cout << ">>Выберите опцию: ";
}

int main()
{
 setlocale(LC_ALL, "RUS");
 cout << "ЛАБОРАТОРНАЯ РАБОТА 20: СПИСКИ." << endl;
 cout << "================================" << endl;

 TList list;
 int choice;
 char value;

 do
 {
  showMenu();
  cin >> choice;
  cin.ignore();

  cout << "===========================" << endl << endl;

  switch (choice)
  {
  case 1: 
   list.create();
   break;
  case 2:
   list.output();
   break;
  case 3:
   cout << "Введите значение для удаления: ";
   cin >> value;
   list.remove(value);
   break;
  case 4:
   list.replace();
   break;
  case 5:
   cout << "Список уничтожен." << endl;
   list.destroy();
   break;
  case 6:
   cout << "Выход из программы." << endl;
   break;
  default:
   cout << "Такой опции не существует." << endl;
  }
 } while (choice != 6);
 return 0;
}
