import os
import fileinput

method = os.environ.get("REQUEST_METHOD", "")

if method == "POST":
	content = ""
	for line in fileinput.input():
		content+=line
	content = content[4:]
	content = content.replace("%09", "")
	content = content.replace("%0D", "")
	content = content.replace("%0A", "")
	content = content.replace("+", " ")

	contentLength = len(content)
	if contentLength < 10:
		extraMessage = "Clear and short!"
	elif contentLength < 50:
		extraMessage = "I see, thank you for sharing your day with us!"
	else:
		extraMessage = "Wow... you had a lot to say"

	variableHtml = f"""
	<div class="wrapper">
        <h1>
            Summary of your day
        </h1>
        <h3>
            {content}
        </h3>
        <h2>
           {extraMessage}
        </h2>       
    </div>
	"""


else:
	variableHtml = """
    <div class="wrapper">
        <div class="title"><span>Raconte !</span></div>
        <form action="" method="post">
        <div class="input-box">
            <textarea placeholder="meh" name="day" id="day" rows="5" cols="30" required></textarea>
        </div>
        <div class="input-box button">
          <input type="submit" value="Partager">
        </div>
      </form>
    </div>
"""

defaultHtml = f"""
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title> Dis nous tout </title> 
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
  <link rel="stylesheet" href="style.css"/>
  <link rel="stylesheet" href="journal.css"/>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.6.0/css/all.min.css" />
</head>
<body>
<div class="body">
    <nav class="navbar fixed-top">
        <div class="container-fluid">
            <a class="navbar-brand" href="#">WEBSERV</a>
            <div class="d-flex">
                <a href="index.html"><img class="navbar_icons" style="margin-right: 15px;" src="home.svg" alt="Go Home"></a>
                <a href="register.html"><img class="navbar_icons" src="user.svg" alt="Register"></a>
                <a href="tell_us.py"><img class="navbar_icons" src="note.svg" alt="Journal"></a>
            </div>
        </div>
    </nav>
	{variableHtml}
</div>
</body>
</html>
"""

print("Status: 200")
print("")

print(defaultHtml)