Public Class CRactangle



    Private _a As Integer = 0
    Private _b As Integer = 0

    Private _email As String
    Public Property email() As String
        Get
            Return _email
        End Get
        Set(ByVal value As String)
            _email = value
        End Set
    End Property
    Sub New(a As Integer, b As Integer)
        _a = a
        _b = b

    End Sub

    Function add()
        Return _a + _b
    End Function

    Property location As String


End Class
