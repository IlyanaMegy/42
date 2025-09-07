class Student {
	// private variable non sharable
	#secret_var = 'secret'

	ecole = 'Jules Ferry'

	constructor(firstname, lastname) {
		this.firstname = firstname
		this.lastname = lastname
	}

	// méthode pour définir la note
	setnote(nbr) {
		this.note = nbr
	}

	getnote() {
		console.log(this.note);
	}

	// setter pour la note
	set notes(nbr) {
		if (Array.isArray(nbr)) {
			this._notes = nbr
		}
	}

	// getter pour la note
	get notes() {
		return this._notes
	}

	// getter pour le nom complet
	get name() {
		return `${this.firstname} ${this.lastname}`
	}

	moyenne(notes) {
		if (Array.isArray(notes) && notes.length > 1) {
			const total = notes.reduce((acc, curr) => acc + curr, 0);
			return total / notes.length;
		}
		return 0;
	}

	ispassing() {
		if (this._notes) {
			return this.moyenne(this._notes) >= 10;
		}
		return false;
	}
}

class SuperStudent extends Student {

	get name() {
		// return `Super ${this.firstname} ${this.lastname}`
		return 'Super ' + super.name
	}

	ispassing() {
		return true;
	}
}

const a = new Student('John', 'Doe');
a.setnote([12, 15, 18])
console.log(a.name); // John Doe
console.log(a.notes); // undefined
console.log(a.getnote()); // [12, 15, 18]
console.log(a.ispassing()); // true
console.log()

const b = new Student('Jane', 'Smith');
b._notes = [10, 3, 16]
console.log(b.name); // Jane Smith
console.log(b.notes); // [10, 3, 16]
console.log(b.ispassing()); // false

const c = new SuperStudent('Alice', 'Johnson');
c.setnote([9, 2, 1])
console.log(c.name); // Super Alice Johnson
console.log(c.notes); // [9, 2, 1]
console.log(c.ispassing()); // true