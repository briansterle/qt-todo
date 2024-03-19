
#include "todo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

ToDo::ToDo(QWidget *parent) : QWidget(parent) {
  tasksList = new QListWidget(this);
  newTaskEdit = new QLineEdit(this);
  addButton = new QPushButton("Add Task", this);
  removeButton = new QPushButton("Remove Completed Tasks", this);

  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  QHBoxLayout *inputLayout = new QHBoxLayout();
  inputLayout->addWidget(newTaskEdit);
  inputLayout->addWidget(addButton);

  mainLayout->addLayout(inputLayout);
  mainLayout->addWidget(tasksList);
  mainLayout->addWidget(removeButton);

  connect(addButton, &QPushButton::clicked, this, &ToDo::addTask);
  connect(removeButton, &QPushButton::clicked, this, &ToDo::removeTask);
}

void ToDo::addTask() {
  QString task = newTaskEdit->text().trimmed();
  if (!task.isEmpty()) {
    tasksList->addItem(task);
    newTaskEdit->clear();
  }
}

void ToDo::removeTask() {
  QList<QListWidgetItem *> items = tasksList->selectedItems();
  for (auto &item : items) {
    delete tasksList->takeItem(tasksList->row(item));
  }
}
