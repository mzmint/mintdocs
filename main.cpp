#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <cmath>
#include <QPainter>
#include <QTabWidget>
#include <QDebug>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("MintCalc");
    window.resize(1920, 1080);
    window.show();

    QTextEdit maint;

    QPushButton save;
    save.setText("Save");
    QObject::connect(&save, &QPushButton::clicked, [&]() {
        QFile file("file.txt");

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << maint.toPlainText();
        file.close();
    }
    });

    QGridLayout layout;
    layout.addWidget(&maint, 0, 0);
    layout.addWidget(&save, 1, 0);
    window.setLayout(&layout);
    return app.exec();
}