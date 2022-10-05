package questao03;

public class Vacina {

	private int codigo;
	private String nome;
	private String lote;

	public Vacina(int codigo, String nome, String lote) {
		this.codigo = codigo;
		this.nome = nome;
		this.lote = lote;
	}

	public int getCodigo() {
		return codigo;
	}

	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getLote() {
		return lote;
	}

	public void setLote(String lote) {
		this.lote = lote;
	}

}
