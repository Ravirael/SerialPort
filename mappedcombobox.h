#ifndef MAPPEDCOMBOBOX_H
#define MAPPEDCOMBOBOX_H

#include <QComboBox>

#include <vector>
#include <utility>

#include <QSerialPortInfo>
#include "serialport.h"

template <typename T>
class MappedComboBox : public QComboBox
{
    std::vector<std::pair<QString, T>> mapping;
public:
    using QComboBox::QComboBox;

    void setMapping(const decltype(mapping) &mapping)
    {
        this->mapping = mapping;
        clear();

        for (const auto &item : this->mapping)
        {
            addItem(item.first);
        }
    }

    T currentElement() const
    {
        return elementAt(currentIndex());
    }

    T elementAt(unsigned index) const
    {
        return mapping[index].second;
    }

private:
    using QComboBox::addItem;
    using QComboBox::addItems;
    using QComboBox::insertItem;
    using QComboBox::insertItems;

};

#endif // MAPPEDCOMBOBOX_H
