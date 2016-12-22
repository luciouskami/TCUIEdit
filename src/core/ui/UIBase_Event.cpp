//
// Created by liu on 2016/12/15.
//

#include "UIBase_Event.h"

namespace TCUIEdit
{

    UIBase_Event::UIBase_Event(UIPackage *package, QPair<QString, QStringList> pair) : UIBase(package)
    {
        this->type = TRIGGER_EVENT;
        this->defaultsFlag = this->categoryFlag = false;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this function is valid
        if (it != pair.second.constEnd())
        {
            this->version = *it++;
        }
        // Value 1+: argument types
        while (it != pair.second.constEnd())
        {
            this->arguments.push_back(QPair<QString, QString>(*it++, ""));
        }
    }

    void UIBase_Event::add(QPair<QString, QStringList> pair)
    {
        if (pair.first == "_Defaults" && !this->defaultsFlag)
        {
            this->defaultsFlag = true;
            auto it = pair.second.constBegin();
            auto it2 = this->arguments.begin();
            while (it != pair.second.constEnd())
            {
                if (it2 != this->arguments.end())
                {
                    (*it2++).second = (*it++);
                }
                else
                {
                    this->arguments.push_back(QPair<QString, QString>("", *it++));
                    it2++;
                }
            }
        }
        else if (pair.first == "_Category" && !this->categoryFlag)
        {
            this->categoryFlag = true;
            auto it = pair.second.constBegin();
            if (it != pair.second.constEnd())
            {
                this->category = *it++;
            }
        }
    }

    const QString UIBase_Event::getDisplayName() const
    {
        return this->name;
    }

    const QString &UIBase_Event::getCategory() const
    {
        return this->category;
    }

    /*void UIBase_Event::displayDetail(UIMainTree *tree)
    {
        this->initDisplayDetail(treeModel);

        treeModel->appendRow(this->formRow("First game version", this->version));

        auto parent = new QStandardItem("Arguments");
        parent->setEditable(false);
        treeModel->appendRow(parent);

        for (auto &it:this->arguments)
        {
            parent->appendRow(this->formRow(it.first, it.second, true));
        }
    }*/
};