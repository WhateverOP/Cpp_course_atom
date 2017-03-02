
class Stack
{
   public:
       Stack();
       ~Stack();

       bool push (double value);
       bool ok();
       bool dump();
       double pop();
       double top();
       size_t capacity();
       size_t size();


   private:
       static const size_t capacity_ = 6;
       static const int POISON_INT = 100500;
       double data_ [capacity_];
       size_t size_ = 0;


};
