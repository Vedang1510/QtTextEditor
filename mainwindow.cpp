#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>
#include <QFont>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    ui->actionSuperScript->setCheckable(true);
    ui->actionSubScript->setCheckable(true);
    ui->actionBold->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream openFile(&file);
    QString text = openFile.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
    }
    else{
        QString file_name = QFileDialog::getSaveFileName(this,"Save file");
        QFile file(file_name);
        file_path = file_name;
        if(!file.open(QFile::WriteOnly | QFile::Text)){
//            QMessageBox::warning(this,"..","file not open");
            return;
        }
        QTextStream saveAsFile(&file);
        QString text = ui->textEdit->toPlainText();
        saveAsFile << text;
        file.flush();
        file.close();
    }
}


void MainWindow::on_actionSaveAs_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Save file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
//        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream saveAsFile(&file);
    QString text = ui->textEdit->toPlainText();
    saveAsFile << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}





void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat format;
        format.setFontWeight(ui->actionBold->isChecked() ? QFont::Bold : QFont::Normal);
        ui->textEdit->mergeCurrentCharFormat(format);
}




void MainWindow::on_actionSubScript_triggered()
{
    if (ui->actionSubScript->isChecked()) {
        ui->actionSuperScript->setChecked(false);  // Uncheck superscript if subscript is checked
    }

    QTextCharFormat format;
    if (ui->actionSubScript->isChecked()) {
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    } else {
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    }
    ui->textEdit->mergeCurrentCharFormat(format);
}



void MainWindow::on_actionSuperScript_triggered()
{
    if (ui->actionSuperScript->isChecked()) {
            ui->actionSubScript->setChecked(false);  // Uncheck subscript if superscript is checked
        }

        QTextCharFormat format;
        if (ui->actionSuperScript->isChecked()) {
            format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
        } else {
            format.setVerticalAlignment(QTextCharFormat::AlignNormal);
        }
        ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_aboutMe_triggered()
{
    QDialog aboutDialog(this);
        aboutDialog.setWindowTitle("About Me");

        QVBoxLayout *layout = new QVBoxLayout(&aboutDialog);

        QLabel *label = new QLabel(&aboutDialog);
        label->setText(
            "<h1>Vedang Sherpura</h1>"
            "<p><strong>Phone:</strong> +91 9327127472</p>"
            "<p><strong>Email:</strong> vedangrsherpura@gmail.com</p>"
            "<p><strong>LinkedIn:</strong> <a href='https://www.linkedin.com/in/vedang-sherpura/'>https://www.linkedin.com/in/vedang-sherpura/</a></p>"
            "<h2>SUMMARY</h2>"
            "<p>Proficient in problem-solving, analytical thinking, and adept at rapid learning. Currently, in the process of exploring diverse domains to ascertain my specific areas of interest and chart a course for both personal and professional advancement. Confident in the ability to apply skills and learning acumen to make valuable contributions to innovative projects.</p>"
            "<h2>EDUCATION</h2>"
            "<p>B. Tech in Computer Engineering, Bharati Vidyapeeth, Pune (CGPA-9.23) Expected 2025</p>"
            "<p>Courses: Design and Analysis of Algorithm, Programming in Java</p>"
            "<p>Relevant Achievements: Management Head of ACES</p>"
            "<p>HSC Science, NIB School of Science, Palanpur (Percentage-75.4%) 2019-21</p>"
            "<h2>SKILLS</h2>"
            "<p><strong>Technical Languages:</strong> C++, Java, JavaScript, MySQL, PHP, Git</p>"
            "<p><strong>Soft Skills:</strong> Problem Solver, Leadership, Teamwork, Time management</p>"
            "<p><strong>Developer Tools:</strong> ReactJs, GitHub, Bootstrap, VsCode, QT</p>"
            "<h2>PROJECTS</h2>"
            "<p><strong>Interactive CV:</strong> Vedang Sherpura</p>"
            "<p>Comprehensive portfolio showcasing the professional profile, skills, education, and projects. Built using HTML, CSS, and JavaScript, this interactive CV presents a visually appealing and informative layout.</p>"
            "<p><strong>TicTacToe-Qt:</strong></p>"
            "<p>Developed a feature-rich TicTacToe game using C++ and the Qt framework, enabling gameplay against a friend or an AI opponent. Implemented the Minimax algorithm to create an intelligent and challenging computer player. Designed an intuitive and responsive user interface, leveraging object-oriented programming principles for clean and maintainable code. This project demonstrates strong skills in C++ programming, UI/UX design with Qt, and AI algorithm implementation.</p>"
            "<p><strong>Cracking the Code: Advances in Expression Solver Technologies:</strong></p>"
            "<p>Developed a robust C++ program that seamlessly transforms infix mathematical expressions into both postfix and prefix notations, while also implementing an accurate evaluation mechanism.</p>"
            "<h2>ACHIEVEMENTS AND LEADERSHIP</h2>"
            "<p>Attained a silver medal in an NPTEL course, underscoring my exemplary learning capabilities. Concurrently, during my tenure as the Management Head of ACES, orchestrated and hosted a coding event with participation exceeding 100 students.</p>"
        );

        label->setTextFormat(Qt::RichText);
        label->setTextInteractionFlags(Qt::TextBrowserInteraction);
        label->setOpenExternalLinks(true);
        label->setWordWrap(true);

        layout->addWidget(label);
        aboutDialog.setLayout(layout);
        aboutDialog.exec();
}

