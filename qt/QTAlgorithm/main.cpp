#include <QCoreApplication>
#include "qt_linked_list.hpp"
#include "qt_array.hpp"
using namespace linked_list;
using namespace test_linked_list;
using namespace array;
using namespace test_array;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //populate_list();
    //test_remove_duplicates();
    test_merge_array();
    return a.exec();
}
