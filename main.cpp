#include <iostream>

using namespace std;

//---TASK 1
class Human {
protected:
  string firstName, lastName, middleName;
  int age;
  double weight;

public:
  Human() {
    firstName = "";
    lastName = "";
    middleName = "";
    age = 0;
    weight = 0.0;
  }
  Human(string first, string last, string middle, int a, double w) {
    firstName = first;
    lastName = last;
    middleName = middle;
    age = a;
    weight = w;
  }
  virtual ~Human() { cout << "Human destructor called" << endl; }
  virtual void print() {
    cout << "Name: " << firstName << " " << lastName << " " << middleName
         << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << " kg" << endl;
  }
  void setAge(int a) { age = a; }
  void setWeight(double w) { weight = w; }
};

class Schoolboy : public Human {
private:
  int grade;

public:
  Schoolboy() : Human() { grade = 0; }
  Schoolboy(string first, string last, string middle, int a, double w, int g)
      : Human(first, last, middle, a, w) {
    grade = g;
  }
  ~Schoolboy() { cout << "Schoolboy destructor called" << endl; }
  void print() {
    Human::print();
    cout << "Grade: " << grade << endl;
  }
  void setAge(int a) {
    age = a;
    grade = age - 6;
  }
  void setGrade(int g) {
    grade = g;
    age = grade + 6;
  }
};

// TASK 2
class Window {
protected:
  int width_;
  int height_;

public:
  Window(int width, int height) : width_(width), height_(height) {}
  virtual void Draw() const {
    std::cout << "Drawing a simple window (" << width_ << "x" << height_ << ")"
              << std::endl;
  }
};

class TitledWindow : public Window {
protected:
  std::string title_;

public:
  TitledWindow(int width, int height, const std::string &title)
      : Window(width, height), title_(title) {}
  void Draw() const override {
    std::cout << "Drawing a titled window (" << width_ << "x" << height_
              << ") with title: " << title_ << std::endl;
  }
};

class ButtonWindow : public TitledWindow {
private:
  std::string button_label_;

public:
  ButtonWindow(int width, int height, const std::string &title,
               const std::string &button_label)
      : TitledWindow(width, height, title), button_label_(button_label) {}
  void Draw() const override {
    std::cout << "Drawing a button window (" << width_ << "x" << height_
              << ") with title: " << title_
              << " and button label: " << button_label_ << std::endl;
  }
};

// TASK 3
class Student {
protected:
  std::string name_;
  std::string surname_;
  int course_;
  float average_mark_;

public:
  Student() {
    name_ = "";
    surname_ = "";
    course_ = 0;
    average_mark_ = 0;
  }
  Student(std::string name, std::string surname, int course, float average_mark)
      : name_(name), surname_(surname), course_(course),
        average_mark_(average_mark) {}

  virtual void print() const {
    std::cout << "Name: " << name_ << ", Surname: " << surname_
              << ", Course: " << course_ << ", Average mark: " << average_mark_
              << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << "Name: " << student.name_ << ", Surname: " << student.surname_
       << ", Course: " << student.course_
       << ", Average mark: " << student.average_mark_;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Student &student) {
    std::cout << "Enter name: ";
    is >> student.name_;
    std::cout << "Enter surname: ";
    is >> student.surname_;
    std::cout << "Enter course: ";
    is >> student.course_;
    std::cout << "Enter average mark: ";
    is >> student.average_mark_;
    return is;
  }

  Student(const Student &other)
      : name_(other.name_), surname_(other.surname_), course_(other.course_),
        average_mark_(other.average_mark_) {}

  Student &operator=(const Student &other) {
    if (this != &other) {
      name_ = other.name_;
      surname_ = other.surname_;
      course_ = other.course_;
      average_mark_ = other.average_mark_;
    }
    return *this;
  }

  virtual ~Student() {}
};

class DiplomaStudent : public Student {
private:
  std::string thesis_title_;

public:
  DiplomaStudent() { thesis_title_ = ""; }
  DiplomaStudent(std::string name, std::string surname, int course,
                 float average_mark, std::string thesis_title)
      : Student(name, surname, course, average_mark),
        thesis_title_(thesis_title) {}

  void print() const override {
    std::cout << "Name: " << name_ << ", Surname: " << surname_
              << ", Course: " << course_ << ", Average mark: " << average_mark_
              << ", Thesis title: " << thesis_title_ << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const DiplomaStudent &student) {
    os << "Name: " << student.name_ << ", Surname: " << student.surname_
       << ", Course: " << student.course_
       << ", Average mark: " << student.average_mark_
       << ", Thesis title: " << student.thesis_title_;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, DiplomaStudent &student) {
    std::cout << "Enter name: ";
    is >> student.name_;
    std::cout << "Enter surname: ";
    is >> student.surname_;
    std::cout << "Enter course: ";
    is >> student.course_;
    std::cout << "Enter average mark: ";
    is >> student.average_mark_;
    std::cout << "Enter thesis title: ";
    is >> student.thesis_title_;
    return is;
  }

  DiplomaStudent(const DiplomaStudent &other)
      : Student(other), thesis_title_(other.thesis_title_) {}

  DiplomaStudent &operator=(const DiplomaStudent &other) {
    if (this != &other) {
      Student::operator=(other);
      thesis_title_ = other.thesis_title_;
    }
    return *this;
  }

  virtual ~DiplomaStudent() {}
};

int main() {
  cout << "---TASK 1---" << endl;
  Human human1("Ivan", "Ivanov", "Ivanovych", 25, 75.5);
  Schoolboy schoolboy1("Petro", "Petrov", "Petrovych", 10, 35.2, 4);

  human1.print();
  cout << endl;
  schoolboy1.print();
  cout << endl;

  human1.setAge(30);
  schoolboy1.setGrade(5);

  human1.print();
  cout << endl;
  schoolboy1.print();
  cout << endl;
  cout << endl << "---TASK 2---" << endl;
  // create a simple window
  Window *simple_window = new Window(400, 300);
  simple_window->Draw();
  delete simple_window;
  // create a titled window
  TitledWindow *titled_window = new TitledWindow(600, 400, "My Titled Window");
  titled_window->Draw();
  delete titled_window;

  // create a button window
  ButtonWindow *button_window =
      new ButtonWindow(800, 500, "My Button Window", "Click Me");
  button_window->Draw();
  delete button_window;

  // create a titled window using a window pointer
  Window *window_ptr = new TitledWindow(500, 350, "Window Pointer Title");
  window_ptr->Draw();
  delete window_ptr;

  // create a button window using a window reference
  TitledWindow titled_window_ref(700, 450, "Title Ref Window");
  Window &ref = titled_window_ref;
  ButtonWindow button_window_ref(900, 600, "Button Ref Window", "Ref Button");
  ref = button_window_ref;
  ref.Draw();
  cout << endl << "---TASK 3---" << endl;
  // testing Student class
  Student student1("John", "Doe", 2, 4.5);
  student1.print();
  std::cout << student1 << std::endl;

  Student student2;
  std::cin >> student2;
  student2.print();
  std::cout << student2 << std::endl;

  Student student3 = student2;
  student3.print();
  std::cout << student3 << std::endl;

  student1 = student3;
  student1.print();
  std::cout << student1 << std::endl;

  // testing DiplomaStudent class
  DiplomaStudent diploma_student1("Jane", "Smith", 4, 4.8,
                                  "The Role of AI in Healthcare");
  diploma_student1.print();
  std::cout << diploma_student1 << std::endl;

  DiplomaStudent diploma_student2;
  std::cin >> diploma_student2;
  diploma_student2.print();
  std::cout << diploma_student2 << std::endl;

  DiplomaStudent diploma_student3 = diploma_student2;
  diploma_student3.print();
  std::cout << diploma_student3 << std::endl;

  diploma_student1 = diploma_student3;
  diploma_student1.print();
  std::cout << diploma_student1 << std::endl;
  return 0;
}
