#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/wind_record.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
    TEST_CLASS(WindProcessingTests)
    {
    public:

        TEST_METHOD(TestEmptyArray)
        {
            // Тест 1: Пустой массив
            WindRecord* records[10] = { nullptr };
            int size = 0;
            int month = 1;

            double result = calculateAverageSpeedInMonth(records, size, month);

            // Ожидаем -1 (нет данных)
            Assert::AreEqual(-1.0, result, 0.001);
        }

        TEST_METHOD(TestMonthWithData)
        {
            // Тест 2: Месяц с данными
            WindRecord* records[3];

            // Создаем тестовые данные
            records[0] = new WindRecord{ 1, 1, "North", 10.0 };  // месяц 1
            records[1] = new WindRecord{ 2, 1, "South", 20.0 };  // месяц 1
            records[2] = new WindRecord{ 1, 2, "East", 30.0 };   // месяц 2

            int size = 3;
            int month = 1; // Ищем среднее для января

            double result = calculateAverageSpeedInMonth(records, size, month);

            // Ожидаем (10.0 + 20.0) / 2 = 15.0
            Assert::AreEqual(15.0, result, 0.001);

            // Освобождаем память
            for (int i = 0; i < size; i++) {
                delete records[i];
            }
        }

        TEST_METHOD(TestMonthWithoutData)
        {
            // Тест 3: Месяц без данных
            WindRecord* records[2];

            records[0] = new WindRecord{ 1, 1, "North", 10.0 };  // месяц 1
            records[1] = new WindRecord{ 2, 1, "South", 20.0 };  // месяц 1

            int size = 2;
            int month = 3; // Ищем март, но данных нет

            double result = calculateAverageSpeedInMonth(records, size, month);

            // Ожидаем -1 (нет данных)
            Assert::AreEqual(-1.0, result, 0.001);

            // Освобождаем память
            for (int i = 0; i < size; i++) {
                delete records[i];
            }
        }
    };
}
