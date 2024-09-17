#if 1

struct Document;

struct IMachine {
    virtual void print(Document &doc) = 0;
    virtual void fax(Document &doc) = 0;
    virtual void scan(Document &doc) = 0;
};

struct MultiFunctionPrinter : IMachine {
    // OK
    void print(Document &doc) override { /* implementation */ }
    void fax(Document &doc) override { /* implementation */ }
    void scan(Document &doc) override { /* implementation */ }
};

struct Scanner : IMachine {
    // Not OK
    void scan(Document &doc) override { /* implementation */ }
};

int main()
{
//complete the code

}


#endif

#if 1
struct IPrinter {
    virtual void print(Document &doc) = 0;
};

struct IFax {
    virtual void fax(Document &doc) = 0;
};

struct IScanner {
    virtual void scan(Document &doc) = 0;
};

struct MultiFunctionPrinter : IPrinter, IFax, IScanner {
    // Implement necessary methods
};

struct Scanner : IScanner {
    // Implement only the scan method
};


#endif
