# hw3NetworkAssigment
Η τρίτη εργασία στο μάθημα "ΠΡΟΗΓΜΕΝΕΣ ΔΙΚΤΥΑΚΕΣ ΤΕΧΝΟΛΟΓΙΕΣ"


#Προηγμένες Δικτυακές Τεχνολογίες Sockets
#Μέρος 3ο
##Ανάθεση:3-12-2020 Παράδοση: Μέρος Γ’ -23/12/2020
##Μέρος Γ’ -Υλοποίηση Client-Server εφαρμογής
1. –Υλοποίηση client/server εφαρμογής με χρήση TCP
Στο στάδιο αυτό θα πρέπει να υλοποιήσετε έναν απλό Sever και έναν απλό Client που επικοινωνούν μεταξύ τους με sockets και χρησιμοποιούν το πρωτόκολλο TCP. Μόλις ο client συνδεθεί στον server, ο server του στέλνει ένα μήνυμα (π.χ Hello World! ) και αμέσως μετά τα δύο προγράμματα τερματίζονται.
Θα χρειαστείτε τις κλήσεις socket(), connect(), send(), recv(), close(), bind(), listen(), accept() και μπορείτε να χρησιμοποιήσετε ότι άλλο θεωρείται χρήσιμο για την υλοποίηση. Θεωρείστε ότι η επικοινωνία βασίζεται σε IPv4.
Δημιουργήστε ένα πρόγραμμα για τον client (π.χ clientTCP.c στο φάκελο net-pro). H IP του server προς το παρόν είναι η 127.0.0.1
Δημιουργήστε επίσης ένα πρόγραμμα για το server (π.χ serverTCP.c στο φάκελο net-pro). Ο server «ακούει» στο port 2019.