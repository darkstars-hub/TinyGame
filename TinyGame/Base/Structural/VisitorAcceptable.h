#ifndef BASE_STRUCTURAL_VISITOR_ACCEPTABLE_H
#define BASE_STRUCTURAL_VISITOR_ACCEPTABLE_H


namespace base::structural {
template<typename T>
class VisitorAcceptable {
public:
    /// <summary>
    /// Žó‚¯“ü‚ê
    /// </summary>
    /// <typeparam name="Visitor"></typeparam>
    /// <param name="out"></param>
    template<typename Visitor>
    void AcceptVisitor(Visitor& out) const {
        out.Visit(static_cast<const T&>(*this));
    }
};
}
#endif // !BASE_STRUCTURAL_VISITOR_ACCEPTABLE_H