#include <stdio.h>

struct NOS
{
    long id;
};

struct Replace
{
    long parent_id;
};

struct HB
{
    bool no_id;
};

////////////////////////////////////////////////////////////////////////

struct IdHandler
{
    virtual long get_id() = 0;
    virtual void set_id(long) = 0;
};

struct IdHandlerNOS : public NOS, IdHandler
{
    long get_id() override { return id; }
    void set_id(long l) override { id = l; }
};

struct IdHandlerReplace : public Replace, IdHandler
{
    long get_id() override       { return parent_id; }
    void set_id(long l) override { parent_id = l; }
};

struct IdHandlerHB : public HB, IdHandler
{
    long get_id() override     {return 0; }
    void set_id(long) override {}
};

////////////////////////////////////////////////////////////////////////

void handle_id(IdHandler * handler, long new_id)
{
    handler->set_id(new_id);
    long id = handler->get_id();
    fprintf( stderr, " id %ld\n", id );
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "C++98 using \n" );

    IdHandlerNOS nos;
    IdHandlerHB  hb;
    IdHandlerReplace  rep;
    
    handle_id(&nos, 17);
    handle_id(&hb,  29);
    handle_id(&rep, 37);
}
