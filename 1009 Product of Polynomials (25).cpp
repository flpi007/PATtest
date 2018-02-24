#include <cstdio>
#include <set>
#include <cmath>
using namespace std;

struct Term {
    int exp;
    float coeff;
    Term(int e, float c): exp(e), coeff(c){};
    Term operator *(Term rhs) const {
        return Term(exp + rhs.exp, coeff * rhs.coeff);
    }
    bool operator <(Term rhs) const {
        return exp < rhs.exp;
    }
};
struct Poly {
    set<Term> terms;
    void Add(Term t){
        auto x = terms.find(t);
        if(x != terms.end()){
            t.coeff += x->coeff;
            terms.erase(x);
        }
        if(fabs(t.coeff) > 0.001){
            terms.insert(t);
        }
    }
    Poly operator *(Poly rhs) const {
        Poly p;
        for(auto i=terms.begin(); i!=terms.end(); i++){
            for(auto j=rhs.terms.begin(); j!=rhs.terms.end(); j++){
                p.Add((*i) * (*j));
            }
        }
        return p;
    }
};
int k;
Poly a, b;
int main()
{
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        int exp; float coeff;
        scanf("%d %f", &exp, &coeff);
        a.Add(Term(exp, coeff));
    }
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        int exp; float coeff;
        scanf("%d %f", &exp, &coeff);
        b.Add(Term(exp, coeff));
    }
    Poly c = a * b;
    printf("%ld", c.terms.size());
    for(auto i=c.terms.rbegin(); i!=c.terms.rend(); i++){
        printf(" %d %.1f", i->exp, i->coeff);
    }
    printf("\n");
    return 0;
}