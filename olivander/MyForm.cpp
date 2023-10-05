#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Data;
using namespace Data::SqlClient;

// Основная функция программы
[STAThreadAttribute] // Атрибут для установки атрибутов потока приложения
void main() {
    // Установка настроек рендеринга и стилей для Windows Forms
    Application::SetCompatibleTextRenderingDefault(false); // Отключение совместимого текстового рендеринга
    Application::EnableVisualStyles(); // Включение стилей Windows Forms

    // Создание и запуск экземпляра формы

    //CLRFORM - название моего проекта, у вас оно будет другое!
    olivander::MyForm form; // Создание экземпляра класса MyForm (предполагается, что такой класс существует в проекте)
    Application::Run(% form); // Запуск приложения с указанием формы в качестве основного окна
}
