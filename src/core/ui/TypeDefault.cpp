//
// Created by liu on 2016/12/11.
//

#include "TypeDefault.h"
#include "Type.h"
#include "package/Package.h"
#include "Project.h"

namespace TCUIEdit { namespace core { namespace ui
{

    TypeDefault::TypeDefault(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_TYPE_DEFAULT;

        this->setName(pair.first, true);

        auto it = pair.second.constBegin();
        // Value 0: script text
        if (it != pair.second.constEnd())
        {
            m_script = *it++;
        }
        // Value 1: display text (if not present, script text will be used)
        if (it != pair.second.constEnd())
        {
            m_display = *it++;
        }
    }

    TypeDefault::~TypeDefault()
    {

    }

    Type *TypeDefault::getOriginType() const
    {
        return (Type *) (m_pkg->project()->matchUI(m_name, TRIGGER_TYPE));
    }

    const QString TypeDefault::formDisplay() const
    {
        auto type = this->getOriginType();
        if (type)
        {
            return type->formDisplay();
        }
        return "";
    }

    const QString &TypeDefault::script() const
    {
        return m_script;
    }

    void TypeDefault::setScript(const QString &script)
    {
        m_script = script;
    }

    QString TypeDefault::trigData()
    {
        QString str = this->_formArgument(1, m_name, m_script);
        if (!m_display.isEmpty())this->_addArgument(str, m_display);
        return str;
    }


}}}