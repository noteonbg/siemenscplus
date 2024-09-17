#include <iostream>

#if 0
// Interface for printing documents
class Printer {
public:
    virtual void print() = 0;
};

// Implementation of printer
class DocumentPrinter : public Printer {
public:
    void print() override {
        std::cout << "Printing document..." << std::endl;
    }
};

// Interface for scanning documents
class Scanner {
public:
    virtual void scan() = 0;
};

// Implementation of scanner
class DocumentScanner : public Scanner {
public:
    void scan() override {
        std::cout << "Scanning document..." << std::endl;
    }
};

// Interface for faxing documents
class Fax {
public:
    virtual void fax() = 0;
};

// Implementation of fax machine
class DocumentFax : public Fax {
public:
    void fax() override {
        std::cout << "Faxing document..." << std::endl;
    }
};

int main() {
    DocumentPrinter printer;
    printer.print();

    DocumentScanner scanner;
    scanner.scan();

    DocumentFax fax;
    fax.fax();

    return 0;
}

#endif

#if 1

#include <iostream>

// Interface for printing documents
class Printer {
public:
    virtual void print() = 0;
    virtual ~Printer() = default;
};

// Implementation of printer
class DocumentPrinter : public Printer {
public:
    void print() override {
        std::cout << "Printing document..." << std::endl;
    }
};

// Interface for scanning documents
class Scanner {
public:
    virtual void scan() = 0;
    virtual ~Scanner() = default;
};

// Implementation of scanner
class DocumentScanner : public Scanner {
public:
    void scan() override {
        std::cout << "Scanning document..." << std::endl;
    }
};

// Interface for faxing documents
class Fax {
public:
    virtual void fax() = 0;
    virtual ~Fax() = default;
};

// Implementation of fax machine
class DocumentFax : public Fax {
public:
    void fax() override {
        std::cout << "Faxing document..." << std::endl;
    }
};

int main() {
    DocumentPrinter printer;
    printer.print();

    DocumentScanner scanner;
    scanner.scan();

    DocumentFax fax;
    fax.fax();

    return 0;
}


#endif
