cricket = ["ram", "chaitanya", "shreyash"]
batminton = ["yogesh", "aditya", "shreyash","chaitanya"]
football = ["soham", "chetan", "shreyash"]
class Students:
    def C_B(self):
        res = []
        for student in cricket:
            if student in batminton:
                res.append(student)
        return res
    
    def Either_C_B(self):
        res = []
        for student in cricket:
            if student not in batminton:
                res.append(student)

        for student in batminton:
            if student not in cricket:
                res.append(student)
        return res

    def neither_C_B(self):
        res = []
        for student in football:
            if student not in cricket and student not in batminton:
                res.append(student)
        return res   
        
    def play_C_F(self):
        res = []
        for student in cricket:
            if student in football:
                res.append(student)
        return res

a = Students()
print(a.C_B())
print(a.Either_C_B())
print(a.neither_C_B())
print(a.play_C_F())