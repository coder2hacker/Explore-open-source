Module Module1

    Sub Main()
        Console.WriteLine("hello word")

        Dim rect1 As New CRactangle(3, 5)
        rect1.email = "ashu.1@gmail.com"
        rect1.location = "chd"

        Console.WriteLine("add is" & rect1.add())
        Console.WriteLine("email is" & rect1.email)
        Console.WriteLine("location is" & rect1.location)
        Console.ReadKey()

    End Sub

End Module
