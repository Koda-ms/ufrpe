package questao01;

public class Produto {
	
	private String codigo;
	private String nome;
	
	public Produto() {
		super();
	}
	
	public Produto(String codigo, String nome) {
		super();
		this.codigo = codigo;
		this.nome = nome;
	}

	public String getCodigo() {
		return codigo;
	}

	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public void mudarNome(String nome) {
		this.nome = nome;
	}

}
