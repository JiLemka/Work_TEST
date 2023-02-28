#ifndef TEMPLATES_LIST_2021_02_11
#define TEMPLATES_LIST_2021_02_11

namespace lab618
{

    struct MyStruct
    {
        int a;
        double b;

        explicit operator bool() const
        {
            if (a != 0 || b != 0)
                return true;
            return false;
        }
    };


    template<class T>
    class CSingleLinkedList
    {
    private:
        struct leaf
        {
            T data;
            leaf* pnext;
            leaf() :data(T()), pnext(nullptr)
            {}

            leaf(const T& _data, leaf* _pnext) : data(_data), pnext(_pnext)
            {
            }

        };
    public:
        class CIterator
        {
        public:
            /* CIterator()
                 : m_pCurrent(0), m_pBegin(0)
             {
             }*/

            explicit operator bool() const
            {
                if (m_pCurrent != nullptr)
                    return true;
                else
                    return false;
            }

            CIterator(leaf* p)
            {
                m_pCurrent = p;
            }

            CIterator(const CIterator& src)
            {
                m_pBegin = src.m_pBegin;
                m_pCurrent = src.m_pCurrent;
            }

            ~CIterator()
            {
                m_pCurrent = nullptr;
                m_pBegin = nullptr;
            }

            CIterator& operator = (const CIterator& src)
            {
                if (this != &src)
                {
                    m_pBegin = src.m_pBegin;
                    m_pCurrent = src.m_pCurrent;
                }

                return *this;
            }

            bool operator != (const CIterator& it) const
            {
                if (m_pCurrent != it.m_pCurrent)
                    return true;
                return false;
            }

            void operator++()
            {
                if (m_pCurrent->pnext)
                    m_pCurrent = m_pCurrent->pnext;
                else  m_pCurrent = nullptr;
            }

            T getData()
            {
                if (m_pCurrent)
                    return m_pCurrent->data;
                return T();
            }

            T& operator* ()
            {
                if (m_pCurrent)
                    return m_pCurrent->data;
            }

            leaf* getLeaf()
            {
                if (m_pCurrent)
                    return m_pCurrent;
                return 0;
            }

            void setLeaf(leaf* p)
            {
                m_pCurrent = p;
            }

            void setLeafPreBegin(leaf* p)
            {
                m_pBegin = p;
            }

            bool isValid() {

                if (m_pCurrent)
                    return true;
                return false;
            }

        private:
            //храним голову списка, если мы находимся перед началом
            leaf* m_pBegin;
            // храним текущее положение
            leaf* m_pCurrent;

            friend class CSingleLinkedList;
        };

    public:

        CSingleLinkedList() :m_pBegin(0), m_pEnd(0) {}


        virtual ~CSingleLinkedList()
        {
            if (m_pBegin == m_pEnd)
                delete m_pBegin;

            leaf* tmp = m_pBegin;
            while (tmp)
            {
                m_pBegin = m_pBegin->pnext;
                delete tmp;
                tmp = m_pBegin;


            }

        }

        void pushBack(const T& data)
        {
            if (!m_pBegin)
            {
                m_pBegin = new leaf(data, nullptr);
                m_pEnd = m_pBegin;
            }
            else
            {
                m_pEnd->pnext = new leaf(data, nullptr);
                m_pEnd = m_pEnd->pnext;
            }

        }

        void pushFront(const T& data)
        {
            leaf* tmp = new leaf(data, m_pBegin);
            m_pBegin = tmp;
        }

        T popFront()   // проверить если нет всех элементов 
        {
            if (m_pBegin)
            {
                T tmp = m_pBegin->data;
                leaf* pn = m_pBegin->pnext;
                delete m_pBegin;
                m_pBegin = pn;
                return tmp;
            }
            else throw "Eror! No element!";
        }

        // изменяет состояние итератора. выставляет предыдущую позицию.
        void erase(CIterator& it)
        {
            if (m_pBegin != m_pEnd && m_pBegin)
            {
                leaf* tmp = m_pBegin;

                while (tmp->pnext != it.m_pCurrent)
                    tmp = tmp->pnext;
                tmp->pnext = it.m_pCurrent->pnext;
                delete it.m_pCurrent;
                it.m_pCurrent = tmp;
                return;

            }
            else if (m_pBegin == m_pEnd)
            {
                delete m_pBegin;
                m_pBegin = nullptr;
                m_pEnd = nullptr;
            }

            it.m_pCurrent = nullptr;
        }

        int getSize()
        {
            if (m_pBegin)
            {
                int count = 0;
                leaf* tmp = m_pBegin;
                while (tmp)
                {
                    count++;
                    tmp = tmp->pnext;

                }

                return count;
            }

            return 0;

        }

        void clear()
        {

            if (m_pBegin)
            {

                leaf* tmp;

                while (m_pBegin)
                {

                    tmp = m_pBegin->pnext;

                    delete m_pBegin;

                    m_pBegin = tmp;



                }

                m_pEnd = nullptr;

            }

        }

        CIterator begin()
        {
            return CIterator(m_pBegin);
        }

    private:
        leaf* m_pBegin, * m_pEnd;
    };




    template<class T>
    class CDualLinkedList
    {
    private:
        struct leaf
        {
            T data;
            leaf* pnext, * pprev;
            leaf(const T& _data, leaf* _pnext, leaf* _pprev) :data(_data), pnext(_pnext), pprev(_pprev)
            {
            }
        };
    public:
        class CIterator
        {
        public:
            CIterator(leaf* p)
            {
                if (p->pprev != nullptr)
                    m_pBegin = p->pprev;
                else if (p->pnext == nullptr)
                    m_pEnd = p->pnext;

                m_pBegin = p->pnext;
                m_pCurrent = p;
            }

            CIterator(const CIterator& src)
            {
                m_pBegin = src.m_pBegin;
                m_pCurrent = src.m_pCurrent;
                m_pEnd = src.m_pEnd;
            }

            ~CIterator()
            {
                m_pCurrent = nullptr;
                m_pBegin = nullptr;
            }

            CIterator& operator = (const CIterator& src)
            {
                if (this != &src)
                {
                    m_pBegin = src.m_pBegin;
                    m_pCurrent = src.m_pCurrent;
                }

                return *this;
            }

            bool operator != (const CIterator& it) const
            {
                if (m_pCurrent != it.m_pCurrent)
                    return true;
                return false;
            }

            void operator++()
            {

                m_pCurrent = m_pBegin;
                if (m_pBegin)
                    m_pBegin = m_pBegin->pnext;
            }

            void operator--()
            {
                m_pCurrent = m_pCurrent->pprev;
            }

            T getData()
            {
                if (m_pCurrent)
                    return m_pCurrent->data;
                return T();
            }

            T& operator* ()
            {
                if (m_pCurrent)
                    return m_pCurrent->data;
            }

            explicit operator bool() const
            {
                if (m_pCurrent != nullptr)
                    return true;
                else
                    return false;
            }

            leaf* getLeaf()
            {
                if (m_pCurrent)
                    return m_pCurrent;
                return 0;
            }

            // применяется в erase и eraseAndNext
            void setLeaf(leaf* p)
            {
                m_pCurrent = p;
            }

            // применяется в erase и eraseAndNext
            void setLeafPreBegin(leaf* p)
            {
                m_pBegin = p;
            }

            // применяется в erase и eraseAndNext
            void setLeafPostEnd(leaf* p)
            {
                m_pEnd = p;
            }

            bool isValid() {

                if (m_pCurrent)
                    return true;
                return false;
            }

        private:
            //храним голову списка, если мы находимся перед началом
            leaf* m_pBegin;
            // храним текущее положение
            leaf* m_pCurrent;
            //храним конец списка, если мы находимся после конца
            leaf* m_pEnd;
            friend class CDualLinkedList;
        };

    public:

        CDualLinkedList() : m_pBegin(nullptr), m_pEnd(nullptr)
        {
        };

        virtual ~CDualLinkedList()
        {
            if (m_pBegin == m_pEnd)
                delete m_pBegin;

            leaf* tmp = m_pBegin;
            while (tmp)
            {
                m_pBegin = m_pBegin->pnext;
                delete tmp;
                tmp = m_pBegin;


            }
        };

        void pushBack(const T& data)
        {
            if (!m_pBegin)
            {
                m_pBegin = new leaf(data, nullptr, nullptr);
                m_pEnd = m_pBegin;
            }
            else
            {
                m_pEnd->pnext = new leaf(data, nullptr, m_pEnd);
                m_pEnd = m_pEnd->pnext;
            }
        }

        T popBack()
        {
            if (getSize())
            {
                T tmp = m_pEnd->data;
                leaf* pn = m_pEnd;
                m_pEnd = pn->pprev;
                m_pEnd->pnext = nullptr;
                delete pn;
                return tmp;
            }
            else throw "Eror! No element!";
        }

        void pushFront(const T& data)
        {

            leaf* pn = new leaf(data, m_pBegin, nullptr);
            m_pBegin->pprev = pn;
            m_pBegin = pn;
        }

        T popFront()
        {
            if (getSize())
            {
                T elem = m_pBegin->data;
                leaf* tmp = m_pBegin;
                m_pBegin = m_pBegin->pnext;
                m_pBegin->pprev = nullptr;
                delete tmp;
                return elem;
            }
            else throw "Eror! No element!";
        }

        // изменяет состояние итератора. выставляет предыдущую позицию.
        void erase(CIterator& it)
        {
            if (it)
            {
                leaf* tmpprev = it.m_pCurrent->pprev;
                leaf* tmpnext = it.m_pCurrent->pnext;
                if (tmpprev)
                    tmpprev->pnext = tmpnext;
                else
                    m_pBegin = tmpnext;
                if (tmpnext)
                    tmpnext->pprev = tmpprev;
                delete it.m_pCurrent;
                it.m_pCurrent = tmpprev;
            }
        }

        // изменяет состояние итератора. выставляет следующую позицию.
        void eraseAndNext(CIterator& it)
        {

            leaf* tmpprev = it.m_pCurrent->pprev;
            leaf* tmpnext = it.m_pCurrent->pnext;
            if (tmpprev)
                tmpprev->pnext = tmpnext;
            else
                m_pBegin = tmpnext;

            tmpnext->pprev = tmpprev;
            delete it.m_pCurrent;
            it.m_pCurrent = tmpnext;

        }

        int getSize()
        {

            if (m_pBegin)
            {
                int count = 0;
                leaf* tmp = m_pBegin;
                while (tmp)
                {
                    count++;
                    tmp = tmp->pnext;

                }

                return count;
            }

            return 0;

        }

        void clear()
        {
            if (m_pBegin)
            {

                leaf* tmp;

                while (m_pBegin)
                {

                    tmp = m_pBegin->pnext;

                    delete m_pBegin;

                    m_pBegin = tmp;



                }



            }
            m_pEnd = nullptr;
        }

        CIterator begin()
        {
            return CIterator(m_pBegin);
        }

        CIterator end()
        {
            return CIterator(m_pEnd);
        }

    private:
        leaf* m_pBegin, * m_pEnd;
    };
};
#endif //#ifndef TEMPLATES_LIST_2021_02_11
