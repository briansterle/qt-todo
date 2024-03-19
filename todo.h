
#ifndef TODO_H
#define TODO_H

#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>

class ToDo : public QWidget {
  Q_OBJECT

public:
  ToDo(QWidget *parent = nullptr);

private slots:
  void addTask();
  void removeTask();

private:
  QListWidget *tasksList;
  QLineEdit *newTaskEdit;
  QPushButton *addButton;
  QPushButton *removeButton;
};

#endif // TODO_H
